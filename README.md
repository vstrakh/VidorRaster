# VidorRaster
This is a hardware line rasterizer for Arduino MKR Vidor 4000

This library is a drop-in replacement for original VidorGraphics library.
drawRoundRect and fillRoundRect() primitives are exposed. They were there in original firmware, but were missing from the api.

This fpga image features same code that is used in original VidorGraphics library, but built with free Nios /e softcore intead of original Nios /f, and using hardware rasterizer.

Currently it does not support the transformations (rotation/flipping), and likely does not go well with Neopixel. I didn't test it.
The rasterizer supports clipping against the screen borders, so it's ok to have some primitives partially outside of the screen.
