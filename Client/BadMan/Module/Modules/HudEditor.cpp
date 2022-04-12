#include "HudEditor.h"
#include "../../DrawUtils.h"
#include "../../Scripting/ScriptManager.h"
#include "../../../Utils/Logger.h"

HudEditor::HudEditor() : IModule(0x0, Category::GUI, "Edit HUD element positions") {

	registerFloatSetting("invPosX", &this->invX, this->invX, 0.f, g_Data.getClientInstance()->getGuiData()->windowSize.x);
	registerFloatSetting("invPosY", &this->invY, this->invY, 0.f, g_Data.getClientInstance()->getGuiData()->windowSize.y);
}



HudEditor::~HudEditor() {
}

const char* HudEditor::getModuleName() {
	return ("Hud Editor");
}



void HudEditor::onPostRender(C_MinecraftUIRenderContext* renderCtx) {
	/*auto clientInstance = g_Data.getClientInstance();
	vec2_t windowSize = g_Data.getClientInstance()->getGuiData()->windowSize;
	vec2_t windowSizeReal = g_Data.getClientInstance()->getGuiData()->windowSizeReal;
	vec2_t mousePosition = *g_Data.getClientInstance()->getMousePos();
	mousePosition = mousePosition.div(windowSizeReal);
	mousePosition = mousePosition.mul(windowSize);
	
	//*/
	static auto clickGuiMod2 = moduleMgr->getModule<ClickGuiMod>();

	//clickGuiMod2->setEnabled(false);


	if (g_Data.isKeyDown(VK_ESCAPE)) {
	//	clickGuiMod2->setEnabled(true);
		this->setEnabled(false);
	}




	/*
	if (g_Data.getClientInstance()->getMouseGrabbed())
		g_Data.getClientInstance()->releaseMouse();
		//*/







}



void HudEditor::onDisable() {

}