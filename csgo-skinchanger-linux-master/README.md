# csgo-skinchanger-linux

Minimal skin & knife changer for 64-bit Counter-Strike: Global Offensive on Linux.

The creation is detailed in the following series of tutorials:
* [An introduction to Source hacking on Linux.](https://aixxe.net/2016/09/linux-skin-changer)
* [Finishing off the skin changer project.](https://aixxe.net/2016/11/knife-changer-csgo)

## Usage
* Edit desired skins in `src/Hooks/FrameStageNotify.cc` around line 37.
* Edit desired view models in `src/Hooks/FrameStageNotify.cc` around line 102.
* Edit desired kill icons in `src/Hooks/FireEventClientSide.cc` around line 20 then `make`.
* Load with method of choice, see my [blog post](https://aixxe.net/2016/09/shared-library-injection) for some options.