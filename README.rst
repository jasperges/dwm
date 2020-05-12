dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

Patches
-------
The ``jasperge`` branch is my personal branch. The following patches are
applied:


   - `attachbelow <https://dwm.suckless.org/patches/attachbelow/>`_
      - new windows are placed below selected client

   - `zoomswap <https://dwm.suckless.org/patches/zoomswap/>`_
      - allows a master and a stack window to swap places rather than every
        window on the screen changing position

   - `vanitygaps <https://github.com/bakkeby/patches/blob/master/dwm/dwm-vanitygaps-6.2.diff>`_
      - adds configurable gaps between windows differentiating between outer,
        inner, horizontal and vertical gaps

   - `stacker <https://dwm.suckless.org/patches/stacker/>`_
      - provides comprehensive utilities for managing the client stack

   - `restartsig <https://dwm.suckless.org/patches/restartsig/>`_
      - adds a keyboard shortcut to restart dwm or alternatively by using kill
        -HUP dwmpid
      - additionally dwm can quit cleanly by using kill -TERM dwmpid

   - `swallow <https://dwm.suckless.org/patches/swallow/>`_
      - this patch adds "window swallowing" to dwm as known from Plan 9's
        windowing system rio
      - clients marked with isterminal in config.h swallow a window opened by
        any child process, e.g. running xclock in a terminal
      - closing the xclock window restores the terminal window in the current
        position

   - `actualfullscreen <https://dwm.suckless.org/patches/actualfullscreen/>`_
      - actually toggle fullscreen for a window, instead of toggling the status
        bar and the monocle layout

   - `alpha <https://dwm.suckless.org/patches/alpha/>`_
      - adds transparency for the status bar

   - `noborder <https://dwm.suckless.org/patches/noborder/>`_
      - removes the border when there is only one window visible

   - `statuspadding <https://dwm.suckless.org/patches/statuspadding/>`_
      - adds configuration options for horizontal and vertical padding in the
        status bar

   - `dwmc <http://dwm.suckless.org/patches/dwmc/>`_
      - a simple dwmc client using a fork of fsignal to communicate with dwm

   - `center <https://dwm.suckless.org/patches/center/>`_
      - adds an iscentered rule to automatically center clients on the current
        monitor

   - modified version of `floatrules <https://dwm.suckless.org/patches/floatrules/>`_
      - this patch adds 2 extra variables to the 'rules' array in config.def.h:
      - floatw, floath (if the window has the rule isfloating, the window will
        spawn with the geometry specified by these vairables)

   - `tagallmon <https://github.com/bakkeby/patches/tree/master/dwm/dwm-tagallmon-6.2.diff>`_
      - move all visible windows to an adjacent monitor

   - `tagmonfixfs <https://github.com/bakkeby/patches/tree/master/dwm/dwm-tagmonfixfs-6.2.diff>`_
      - allows moving a fullscreen window to another monitor while remaining in
        fullscreen

   - `tagswapmon <https://github.com/bakkeby/patches/tree/master/dwm/dwm-tagswapmon-6.2.diff>`_
      - swap all visible windows on one monitor with those of an adjacent
        monitor
      - *tweak*: the current monitor stays active instead of keeping the current
        window in focus

   - `bstack <https://dwm.suckless.org/patches/bottomstack/>`_
      - bottomstack layout

   - `pertag <https://dwm.suckless.org/patches/pertag/>`_
      - adds nmaster, mfact, layouts and more per tag rather than per monitor

   - `savefloats <https://dwm.suckless.org/patches/save_floats/>`_
      - saves size and position of every floating window before it is forced
        into tiled mode
      - if the window is made floating again then the old dimensions will be
        restored

   - `losefullscreen <https://github.com/bakkeby/patches/tree/master/dwm/dwm-losefullscreen-6.2.diff>`_
      - by default in dwm it is possible to make an application fullscreen, then
        use the focusstack keybindings to focus on other windows beneath the
        current window
      - it is also possible to spawn new windows (e.g. a terminal) that end up
        getting focus while the previous window remains in fullscreen
      - this patch ensures that in such scenarios the previous window loses
        fullscreen

   - `nametag <https://dwm.suckless.org/patches/nametag/>`_
      - this patch allows you to change the names of dwm's tags while it's
        running. By default there is a 16 byte limit on tag names, and it uses
        dmenu to prompt for tag names
      - the prepend version prepends the tag name with a short string
      - by default a tag name "foo" given to tag 5 will become tag
        "5:foo"
      - *tweak*: an emtpy name will only show the number again

   - `resizecorners <https://dwm.suckless.org/patches/resizecorners/>`_
      - by default, windows only resize from the bottom right corner
      - with this patch the mouse is warped to the nearest corner and you resize
        from there

   - `statuscmd-signal <https://dwm.suckless.org/patches/statuscmd/>`_
      - send a SIGUSR1 signal to dwmblocks with the button and control character
        encoded into the signal value
      - the dwmblocks-statuscmd patch makes dwmblocks put each block's signal in
        front of its output text and handles the SIGUSR1 signal by running the
        block's command with $BUTTON exported
