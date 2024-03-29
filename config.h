/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx    = 4;        /* border pixel of windows */
static const unsigned int snap        = 32;       /* snap pixel */
static const unsigned int gappih      = 8;        /* horiz inner gap between windows */
static const unsigned int gappiv      = 8;        /* vert inner gap between windows */
static const unsigned int gappoh      = 8;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov      = 8;        /* vert outer gap between windows and screen edge */
static const int smartgaps            = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar              = 1;        /* 0 means no bar */
static const int topbar               = 1;        /* 0 means bottom bar */
static const int horizpadbar          = 8;        /* horizontal padding for statusbar */
static const int vertpadbar           = 8;        /* vertical padding for statusbar */
static const int pertag               = 1;        /* 0 means global layout across all tags (default), 1 = layout per tag (pertag) */
static const int pertagbar            = 0;        /* 0 means using pertag, but with the same barpos, 1 = normal pertag */
static const int savefloats           = 1;        /* 0 means default behaviour, 1 = savefloats patch */
static const char *fonts[]            = { "Ubuntu Nerd Font:size=11:antialias=true" };
static const char dmenufont[]         = "Ubuntu Nerd Font:size=11:antialias=true";
static const char col_gray1[]         = "#222222";
static const char col_gray2[]         = "#444444";
static const char col_gray3[]         = "#bbbbbb";
static const char col_gray4[]         = "#eeeeee";
static const char col_cyan[]          = "#285577";
static const unsigned int baralpha    = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
#define MAX_TAGNAME_LEN 14      /* excludes TAG_PREPEND */
#define TAG_PREPEND "%1i:"      /* formatted as 2 chars */
#define MAX_TAGLEN 16           /* altogether */
static char tags[][MAX_TAGLEN] = { "", "", "", "", "5", "6", "", "", "" };
/* static char tags[][MAX_TAGLEN] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
/* static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance  title                  tags mask  iscentered  float w, h  isfloating  isterminal  doswallow  monitor */
	{ "krita",              NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Gimp",               NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Firefox",            NULL,     NULL,                  1 << 8,    0,          -1, -1,     0,          0,          0,          0 },
	{ "Badwolf",            NULL,     NULL,                  1 << 8,    0,          -1, -1,     0,          0,          0,          0 },
	{ "Mattermost",         NULL,     NULL,                  1 << 7,    0,          -1, -1,     0,          0,          0,          1 },
	{ "TelegramDesktop",    NULL,     "Telegram",            1 << 7,    0,          -1, -1,     0,          0,          0,          1 },
	{ "TelegramDesktop",    NULL,     "Media viewer",        0,         0,          -1, -1,     1,          0,          0,         -1 },
	{ "Rambox",             NULL,     NULL,                  1 << 7,    0,          -1, -1,     0,          0,          0,          1 },
	{ "Franz",              NULL,     NULL,                  1 << 7,    0,          -1, -1,     0,          0,          0,          1 },
	{ "Signal",             NULL,     NULL,                  1 << 7,    0,          -1, -1,     0,          0,          0,          1 },
	{ "Spotify",            NULL,     "Spotify",             1 << 6,    0,          -1, -1,     0,          0,          0,          1 },
	/* Deadline Monitor -> workspace 7 */
	{ NULL,                 NULL,     "Deadline Monitor",    1 << 6,    0,          -1, -1,     0,          0,          0,          0 },
	/* Blender -> workspace 4 */
	{ "Blender",            NULL,     NULL,                  1 << 3,    0,          -1, -1,     0,          0,          0,          0 },
	/* Conferencing apps -> workspace 8 */
	{ "Jitsi Meet",         NULL,     NULL,                  1 << 7,    0,          -1, -1,     0,          0,          0,          0 },
	{ "zoom",               NULL,     NULL,                  1 << 7,    0,          -1, -1,     0,          0,          0,          0 },
	{ "Droidcam",           NULL,     NULL,                  1 << 7,    0,			-1, -1,     0,          0,          0,          0 },
	{ "Pavucontrol",        NULL,     NULL,                  1 << 7,    0,			-1, -1,     0,          0,          0,          0 },
	/* Terminals */
	{ "st",                 NULL,     NULL,                  0,         0,          -1, -1,     0,          1,          0,         -1 },
	{ "alacritty",          NULL,     NULL,                  0,         0,          -1, -1,     0,          1,          0,         -1 },
	/* Make apps floating */
	/* Movie player */
	{ "mpv",                NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "djv",                NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Terminal pinentry */
	{ "alacritty",          NULL,     "pinentry",            0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Avalon/Allzpark/Torpedo */
	{ "cli.py",             NULL,     "Torpedo",             0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "cli.py",             NULL,     "Project",             0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Shotgun */
	{ "Shotgun",            NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* File managers */
	{ "Thunar",             NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Pcmanfm",            NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	 /* Blender */
	{ "Blender",            NULL,     "Blender Preferences", 0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Blender",            NULL,     "Render",              0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "blender",            NULL,     "Work Files",          0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "blender",            NULL,     "Context Manager",     0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "blender",            NULL,     "Instance Creator",    0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "blender",            NULL,     "Asset Loader",        0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "blender",            NULL,     "Pyblish",             0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "blender",            NULL,     "Scene Inventory",     0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Maya */
	{ "Maya",               NULL,     NULL,                  0,         0,          -1, -1,     0,          0,          0,         -1 },
	{ "Maya",               NULL,     "JJM Playblast",       0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Script Editor",       0,         1,        1400, 900,    1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Edit Layer",          0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Work Files",          0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Context Manager",     0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Instance Creator",    0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Asset Loader",        0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Pyblish",             0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "__main__.py",        "__main__.py", "Pyblish",        0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "Maya",               NULL,     "Scene Inventory",     0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Bluetooth manager */
	{ "Blueman-manager",    NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Steam */
	{ "Steam",              NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Bash/Htop */
	{ "alacritty",          NULL,     "centered",            0,         1,        1400, 900,    1,          0,          0,         -1 },
	/* Float */
	{ "Dwarf_Fortress",     NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "pdfmerge_qt",        NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	{ "ProtonMail Bridge",  "protonmail-bridge", NULL,       0,         1,         785, 530,    1,          0,          0,         -1 },
	{ "__main__.py",        NULL,     "GazUser",             0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Syncthing */
	{ "Syncthing GTK",      NULL,     NULL,                  0,         1,          -1, -1,     1,          0,          0,         -1 },
	/* Swallow */
	{ "Zathura",            NULL,     NULL,                  0,         0,          -1, -1,     0,          0,          1,         -1 },
	{ "libreoffice",        NULL,     NULL,                  0,         0,          -1, -1,     0,          0,          1,         -1 },
	{ "Sxiv",               NULL,     NULL,                  0,         0,          -1, -1,     0,          0,          1,         -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static int attachbelow       = 1;    /* 1 means attach after the currently active window */

#include "layouts.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "start_terminal_in_pwd", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* { MODKEY,                       XK_p,      spawn,             {.v = dmenucmd } }, */
	{ MODKEY,                       XK_Return, spawn,             {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,         {0} },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,                       XK_comma,  incnmaster,        {.i = +1 } },
	{ MODKEY,                       XK_period, incnmaster,        {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,          {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,          {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,          {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,          {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,          {.f =  0.00} },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,          {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,          {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,         {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,         {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,        {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,       {0} },
	{ MODKEY|Mod1Mask,              XK_Return, toggleAttachBelow, {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,              {0} },
	{ MODKEY,                       XK_Tab,    view,              {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,        {0} },
	{ MODKEY,                       XK_t,      setlayout,         {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,         {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,         {.v = &layouts[2]} },
	{ MODKEY,                       XK_e,      setlayout,         {.v = &layouts[3]} }, // bstack layout
	{ MODKEY,                       XK_r,      setlayout,         {.v = &layouts[4]} }, // bstackhoriz layout
	{ MODKEY,                       XK_u,      setlayout,         {.v = &layouts[5]} }, // centered master
	{ MODKEY|ShiftMask,             XK_u,      setlayout,         {.v = &layouts[6]} }, // centered floating master
	{ MODKEY|ControlMask,           XK_space,  setlayout,         {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,    {0} },
	{ MODKEY,                       XK_f,      togglefullscr,     {0} },
	{ MODKEY,                       XK_0,      view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,               {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_comma,  focusmon,          {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, focusmon,          {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,            {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,            {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_comma,  tagallmon,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_period, tagallmon,         {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_comma,  tagswapmon,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_period, tagswapmon,        {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_slash,  nametag,           {0} },
	TAGKEYS(                        XK_1,                         0)
	TAGKEYS(                        XK_2,                         1)
	TAGKEYS(                        XK_3,                         2)
	TAGKEYS(                        XK_4,                         3)
	TAGKEYS(                        XK_5,                         4)
	TAGKEYS(                        XK_6,                         5)
	TAGKEYS(                        XK_7,                         6)
	TAGKEYS(                        XK_8,                         7)
	TAGKEYS(                        XK_9,                         8)
	{ MODKEY|ControlMask|ShiftMask, XK_BackSpace,      quit,     {0} },
	{ MODKEY|ShiftMask,             XK_BackSpace,      quit,     {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};

/* vim: set ts=4 sw=4 tw=0 noet :*/
