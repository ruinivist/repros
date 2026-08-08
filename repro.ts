import { createCliRenderer, link, t, TextRenderable } from "@opentui/core"

const url = "https://www.example.com/this/is/a/very/long/link/designed/to/span/across/at/least/two/lines/in/most/chat/windows/with/additional/path/segments/and/a/long-query-string?category=software-development&topic=testing-long-links-in-chat&reference=1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

const renderer = await createCliRenderer({ exitOnCtrlC: true })
renderer.root.add(new TextRenderable(renderer, {
  content: t`${link(url)(url)}`,
  width: "100%",
}))

renderer.start()
