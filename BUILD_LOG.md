# KACTL Build Log

## 2026-10-28

- Added Ahnaf Shahriar Asif and Irfan Rahman Rasib to the cover team list; retained MTB Ishmam.
- Enabled a build-time color switch and added `make colored` plus `make build-all` to generate monochrome and colored PDFs after tests.
- Requested headers for this build: `content/data-structures/segtree.h` and `content/number-theory/mint.h`.
- Added `BUILD_SOP.md` to make the test, build, visual verification, and logging workflow repeatable.
- Test results with GNU GCC 16: `make test-compiles` reported 110/166 headers passing; `make test` reported 5/82 stress tests passing. The repository-wide suites are not clean (for example, standalone headers fail on missing declarations, type mismatches, and missing dependencies), so `make build-all` exits nonzero after attempting both PDF builds.
- Targeted checks: a GNU GCC smoke test of `segtree.h` updates and range queries passed; `mint.h` passed its stress test when compiled with `<cassert>` explicitly included.
- PDF results: both monochrome and colored KACTL PDFs built successfully with 26 pages each (cover plus 25 content pages). Their extracted text includes all three team members and the requested `segtree.h` and `mint.h` content.
- Visual verification: rendered and inspected the cover, segment tree page, modular integer page, and the updated contest instructions page in both versions; no clipping or layout defects found. The colored version shows syntax colors.
- Added a listings mapping for the right-arrow glyph in the already modified contest instructions so the document compiles under the installed TeX engine.
- Added the user's 2D Fenwick tree update (`fakeUpd` usage) and current `mint.h` changes to this build's differences; both current headers are included in the generated PDFs.
- Initially reduced imported filename headings, then restored the designed `\large` size after review. The labels and code listings use the same embedded Nimbus Mono (Courier) typeface; the document explicitly loads `courier` for this design.
- Replaced the hard-coded cover date with `\today`, formatted as `D Month, YYYY` (for example, `28 October, 2026`), so future builds display the generation date automatically.
- Follow-up clean build: cleared both variants' LaTeX intermediates, then ran `make build-all` with GNU GCC 16 before PDF generation. The repository suites again reported 110/166 header compile tests and 5/82 stress tests passing; `build-all` exited nonzero because those suites fail. Both standard two-pass PDF targets nevertheless completed successfully, with 26 pages each and PDF creation dates of 2026-10-28.
- Targeted checks on the current source passed: `segtree.h`, `FenwickTree2d.h` (including the current `fakeUpd` usage note), and the current `mint.h` stress test.
- Extracted text and rendered pages from both regenerated PDFs were checked. That intermediate build had all three names and the ISO date; its heading-size change was subsequently reverted as recorded below.
- Expanded `make clean` to remove both monochrome and colored LaTeX intermediates so future SOP builds start fresh. GitHub push was not performed; the user said they will authorize it later.
- Font diagnosis: the installed TeX Live 2026 BasicTeX setup finds `courier.sty`, its Courier metrics, and the URW Courier font file, which is embedded in the PDFs as Nimbus Mono. PDF inspection shows the code listings use that same font family. The font difference was not caused by macOS or a missing regular typewriter font, so a full TeX install was not needed.
- Final rebuild: restored `\large` headings, changed the automatic cover date to `28 October, 2026` format, and included the latest indentation-stripped `mint.h`. After clean full tests (110/166 header compile tests and 5/82 stress tests passed), both two-pass PDF builds succeeded at 26 pages. Extracted text confirms the requested date, team names, current `FenwickTree2d.h`, and current `mint.h`; the cover and code page were visually inspected.
- Targeted test of the latest `mint.h` passed (`Tests passed!`). Full repository suites remain nonzero, as above.
- Typography correction: imported filenames now use `\normalfont\large\bfseries`, matching the serif family and bold weight of subsection headings such as “Trivia” while preserving the designed `\large` command. This intentionally changes filename labels from Courier to serif bold.
- Rebuilt after the typography correction and latest `mint.h` update. Both final PDFs have 26 pages and show `28 October, 2026`; extracted PDF font records show both “Trivia” and `segtree.h` in Computer Modern bold Roman. The full test counts remain 110/166 compile checks and 5/82 stress tests; both PDF targets succeeded.

## 2026-10-28

- Restored `content/contest/stress.bat` readability by putting the executable reminder and `set i=1` on separate lines; the current source and PDF therefore report 12 physical lines.
- Fixed the large blank bands between imported listings by enabling `\\raggedcolumns` in the four-column document. This prevents `multicol` from stretching flexible vertical gaps to force equal column bottoms; the result keeps compact source transitions and leaves natural white space at the bottom of shorter columns.
- Updated `BUILD_SOP.md` to preserve readable source comments, use current physical line counts, and retain ragged columns for future builds.
- Ran both repository checks before PDF generation: GNU GCC header compilation passed 110/166 cases; stress tests passed 5/82. `make build-all` returned nonzero because of these existing suite failures, but both two-pass PDF builds completed successfully.
- Regenerated monochrome and colored PDFs from a clean LaTeX state. Both are 26 pages, contain all three team names, show the generated date as `28 October, 2026`, and list `stress.bat` as 12 lines.
- Rendered and visually inspected page 2 of both variants. The excessive gaps between `rte.sh`, `cf.bat`, and `stress.bat` are gone; the restored comment and initialization appear on separate lines.
- Final follow-up build after removing the orphaned comment-period wrap completed both two-pass outputs; the same repository test totals were recorded before PDF compilation. Final monochrome and colored page-2 renders were both visually inspected.

## 2026-10-29

- Per the build SOP, cleared the LaTeX intermediates and ran `make build-all` with GNU GCC 16.1 before PDF output generation.
- Repository checks reported 110/166 header compile tests and 5/82 stress tests passing, so `make build-all` exited nonzero after its test stages. Both normal two-pass PDF builds nevertheless completed successfully.
- Regenerated `kactl.pdf` and `kactl_colored.pdf`; each is 26 pages and its cover shows all three team members and `29 October, 2026`.
- Extracted PDF text confirms current `segtree.h`, `FenwickTree2d.h`, and `mint.h` listings. Rendered and visually inspected the cover plus relevant code pages in both color variants; no clipping or spacing defects found.
