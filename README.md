# Julia_Mandelbrot
My implementation of 42's fract’ol but the Mandelbrot is a Julia set map


LINUX INSTALL

1. Clone this repo and cd into it.
2. Clone the following repo :
   https://github.com/42paris/minilibx-linux
3. Check the dependencies of minilibx and, if required, install them.
   NOTE: minilibx does not build with a recent gcc, hack all Makefile.mk files to set the compiler to clang.
5. make


RUNNING

Run ./fractol without options to display the following help:

```
Usage: ./fractol <type> [options]

<type>:
  m              - Mandelbrot set (z^2 + c)
  m ship         - Burning Ship fractal
  m tricorn      - Tricorn fractal (Mandelbar)
  j [preset|c]   - Julia set (z^2 + c)
  j ship         - Julia set with Ship equation
  j tricorn      - Julia set with Tricorn equation

Julia Presets (use 'j' followed by a key):
  d - Dragon (c = -0.4 + 0.6i) (default)
  s - Dense Spirals (c = -0.7 + 0.27i)
  e - Elephant Valley (c = -0.835 - 0.232i)
  t - Thin Dendrite (c = 0.285 + 0.01i)
  l - Lightning Bolt (c = -0.1 + 0.651i)
  h - Seahorse (c = 0.0 + 0.8i)

Julia Custom (use 'j c' followed by values):
  c <real> <imag>   (e.g., j c -0.4 0.6)
     real: [-2.0 ... 2.0]
     imag: [-2.0 ... 2.0]

Examples:
  ./fractol m
  ./fractol m ship
  ./fractol j d
  ./fractol j c 0.42 0.42
```

ONCE INSIDE

  1. Use the mouse wheel to zoom in and out.
  2. Use the arrow keys to move the fractal around.
  3. R/r to restore the initial position and size.
  4. C/c to change the colour palette (eight available).
  5. T/t to toggle on/off the colour shift animation.
  6. Click anywhere on the Mandelbrot to open the corresponding Julia set (the cutests Julias are around the edges).
  7. ESC to exit.
