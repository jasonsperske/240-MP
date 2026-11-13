#!/usr/bin/env bash
# Refresh the vendored bike library (android/vendor/bike-core, android/vendor/bike) from a
# soloton checkout. Same approach as ExerDoom's script of the same name.
#
#   scripts/sync-bike-lib.sh                       ../soloton at origin/main
#   scripts/sync-bike-lib.sh ~/dev/soloton v0.2.0  another checkout or ref
#
# Replaces everything upstream owns (sources, tests, LICENSE, README) and keeps this repo's own
# build.gradle files (upstream's need soloton's convention plugins and a newer AGP than Qt 6.4's
# Android template), then records the commit in android/vendor/UPSTREAM. Review with git diff.
set -euo pipefail

here="$(cd "$(dirname "$0")/.." && pwd)"
soloton="${1:-$here/../soloton}"
ref="${2:-origin/main}"

git -C "$soloton" fetch --quiet origin || echo "warning: could not fetch $soloton; using what it has" >&2
commit="$(git -C "$soloton" rev-parse "$ref^{commit}")"

for module in bike-core bike; do
    dest="$here/android/vendor/$module"
    keep="$(mktemp)"
    cp "$dest/build.gradle" "$keep"
    rm -rf "$dest"
    tmp="$(mktemp -d)"
    git -C "$soloton" archive "$commit" "libs/$module" | tar -x -C "$tmp"
    mv "$tmp/libs/$module" "$dest"
    rm -rf "$tmp" "$dest/build.gradle.kts"
    cp "$keep" "$dest/build.gradle"
    rm "$keep"
done

sed -i "s/^commit=.*/commit=$commit/" "$here/android/vendor/UPSTREAM"
echo "android/vendor/bike-core and android/vendor/bike now at soloton $commit"
