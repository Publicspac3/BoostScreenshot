#include "pch.h"
#include "BoostScreenshot.h"


BAKKESMOD_PLUGIN(BoostScreenshot, "No gui boost screenshots", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void BoostScreenshot::onLoad()
{
	_globalCvarManager = cvarManager;
	cvarManager->log("Boost Screenshot Plugin loaded!");

	cvarManager->registerNotifier("Gui_Remove", [&](std::vector<std::string> params) {Gui_Remove();  }, "GUI is removed and FOV set to 80", PERMISSION_MENU);
	cvarManager->registerNotifier("Gui_Add", [&](std::vector<std::string> params) {Gui_Add(); }, "GUI and FOV is set back to normal", PERMISSION_MENU);
	
}

void BoostScreenshot::onUnload()
{
	cvarManager->executeCommand("cl_rendering_scaleform_disabled 0; cl_mainmenu_fov 55");
}
void BoostScreenshot::Gui_Remove()
{
	cvarManager->executeCommand("cl_rendering_scaleform_disabled 1; cl_mainmenu_fov 80");
	
}
void BoostScreenshot::Gui_Add()
{
	cvarManager->executeCommand("cl_rendering_scaleform_disabled 0; cl_mainmenu_fov 55");
}

////////// ok so i want to figure out how to call a change in the menu but no idea how lol 