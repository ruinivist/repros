# OpenTUI wrapped hyperlink repro

Reproduces a long hyperlink becoming truncated when OpenTUI's direct `link()`
API wraps it across terminal rows.

## Run

Requires Bun 1.3 or newer and a terminal with OSC 8 hyperlinks enabled.

```sh
bun install
bun start
```

Resize the terminal until the URL wraps, then try opening it. Press
`Ctrl+C` to exit.

## Expected result

The complete URL should be clickable from every wrapped row. In Konsole, only
the first row is clickable and opens a URL truncated at the row boundary.
