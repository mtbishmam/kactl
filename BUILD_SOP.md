# KACTL PDF Build SOP

Run this workflow whenever Ishmam asks to build the KACTL PDF.

1. Read this file and `BUILD_LOG.md`. Check `git status` and preserve unrelated edits.
2. Confirm the cover has the current team members and uses `\today` for the generated-on date, formatted as `D Month, YYYY` (for example, `28 October, 2026`). Style imported source filenames with `\normalfont\large\bfseries` in `\kactlimport` so they match subsection headings. Preserve readable source formatting, including comments on their own lines; report the actual physical line count in each listing. Inspect the requested headers and include user-updated files such as `content/data-structures/FenwickTree2d.h`, `content/data-structures/segtree.h`, and `content/number-theory/mint.h` in the difference log.
3. On macOS, make sure GNU GCC and its matching `cpp` are first on `PATH` (Apple's `g++` is Clang and does not support the KACTL header hash command). Make sure `pdflatex` is available, run `make clean` to clear both PDF variants' LaTeX intermediates, then run `make build-all`. This runs the header compile suite and stress tests before attempting either final PDF, then builds both with the normal two-pass LaTeX command (never `make fast`). Keep `\raggedcolumns` enabled in the four-column layout so `multicol` does not stretch vertical gaps between listings to fill column bottoms.
4. Check both PDFs with `pdfinfo`, extract text to confirm the names, generated-on date in `D Month, YYYY` form, and requested header contents, render pages with `pdftoppm`, and visually inspect the cover and pages containing the changed headers. Verify filename headings match the serif, bold subsection heading style and source-to-source spacing is compact and even.
5. Append a dated entry to `BUILD_LOG.md` describing source/document changes, test results, PDF outputs, and any limitation. Do not claim a PDF is complete if a build or verification step failed.

The `build-all` target is the standard command for future builds. A standalone `make kactl` creates only the monochrome PDF; `make colored` creates only the colored PDF and assumes the compile/test steps were already run.
