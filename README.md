# SK00BY
SK00BY is a improved version of Chameleon by @axxie. Personally I felt like I needed to change a few things to make it safer and easier to use. 


HOW TO INJECT:

1. Download the file and extract it somewhere
2. Open terminal and type cd then drag the folder into it
3. Then type in make
4. Then type exit or quit depending on what you OS allows
5. Open CSGO
6. Type sudo gdb -ex "attach $(pidof csgo_linux64)" into terminal
7. Then type set $dlopen = (void*(*)(char*, int)) dlopen
8. Then type set $dlclose = (int(*)(void*)) dlclose
9. After this type set $library = $dlopen("/PATH-TO-FILE", 1)
10. Then type continue


HOW TO CHANGE YOUR SKIN:

1. Go into skins.h
2. This is where all the skin files are stored, for example
// Example to replace the default CT knife with a ★ Karambit | Fade.
inline void SetSkinConfig() {
	g_SkinChangerCfg[WEAPON_KNIFE].iItemDefinitionIndex = WEAPON_KNIFE_KARAMBIT;
	g_SkinChangerCfg[WEAPON_KNIFE].nFallbackPaintKit = 38;
	g_SkinChangerCfg[WEAPON_KNIFE].iEntityQuality = 3;
}
 
inline void SetModelConfig() {
	int nOriginalKnifeCT = g_ModelInfo->GetModelIndex("models/weapons/v_knife_default_ct.mdl");
	g_ViewModelCfg[nOriginalKnifeCT] = "models/weapons/v_knife_karam.mdl";
}
 
inline void SetKillIconCfg() {
	g_KillIconCfg["knife_default_ct"] = "knife_karambit";
}

3. This is code that is already in the skins.h file and will change your skins
4. If you want to change the default skins I have set just find the CS-GO skins file and paste it here
