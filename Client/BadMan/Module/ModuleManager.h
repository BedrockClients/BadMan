#pragma once

#include <typeinfo>
#include <vector>
#include <optional>
#include <memory>
#include <mutex>
#include <shared_mutex>

#include "../../Memory/GameData.h"
#include "../../SDK/COption.h"

#include "Modules/Aimbot.h"
#include "Modules/R9J9ServerFly.h"
#include "Modules/ShulkerExploit.h"
#include "Modules/AntiHunger.h"
#include "Modules/NoEntityTrace.h"
#include "Modules/AntiAnvil.h"
#include "Modules/AltTheme.h"
#include "Modules/Background.h"
#include "Modules/NoEntityRender.h"
#include "Modules/surround.h"
#include "Modules/DvdLogo.h"
#include "Modules/AutoEz.h"
#include "Modules/NoMiningTrace.h"
#include "Modules/Targethud.h"
#include "Modules/cps.h"
#include "Modules/Bps.h"
#include "Modules/fps.h"
#include "Modules/NoFall.h"
#include "Modules/CrosshairPlus.h"
#include "Modules/SessionInfo.h"
#include "Modules/InventoryView.h"
#include "Modules/NukkitNoFall.h"
#include "Modules/ElytraFly.h"
#include "Modules/CrystalAuraOW.h"
#include "Modules/AutoTrap.h"
#include "Modules/CustomSky.h"
#include "Modules/Auto32k.h"
#include "Modules/TPAura.h"
#include "Modules/ForceTotem.h"
#include "Modules/DeathCoords.h"
#include "Modules/AirJump.h"
#include "Modules/AirSwim.h"
#include "Modules/AntiBot.h"
#include "Modules/AutoArmor.h"
#include "Modules/AutoClicker.h"
#include "Modules/AutoGapple.h"
#include "Modules/AutoSneak.h"
#include "Modules/AutoSprint.h"
#include "Modules/AutoTotem.h"
#include "Modules/Fucker.h"
#include "Modules/Bhop.h"
#include "Modules/Blink.h"
#include "Modules/BowAimbot.h"
#include "Modules/AntiVoid.h"
#include "Modules/ChestAura.h"
#include "Modules/ChestESP.h"
#include "Modules/ChestStealer.h"
#include "Modules/ClickGuiMod.h"
#include "Modules/Teleport.h"
#include "Modules/Crasher.h"
#include "Modules/Criticals.h"
#include "Modules/CrystalAura.h"
#include "Modules/Derp.h"
#include "Modules/ESP.h"
#include "Modules/EditionFaker.h"
#include "Modules/FastEat.h"
#include "Modules/FastLadder.h"
#include "Modules/Fly.h"
#include "Modules/Freecam.h"
#include "Modules/FullBright.h"
#include "Modules/Glide.h"
#include "Modules/HighJump.h"
#include "Modules/Hitbox.h"
#include "Modules/HudModule.h"
#include "Modules/ExtendedBlockReach.h"
#include "Modules/InfiniteReach.h"
#include "Modules/InstaBreak.h"
#include "Modules/InventoryCleaner.h"
#include "Modules/InventoryMove.h"
#include "Modules/Jesus.h"
#include "Modules/Jetpack.h"
#include "Modules/Killaura.h"
#include "Modules/MidClick.h"
#include "Modules/Module.h"
#include "Modules/NameTags.h"
#include "Modules/NoFriends.h"
#include "Modules/Velocity.h"
#include "Modules/NoPacket.h"
#include "Modules/NoSlowDown.h"
#include "Modules/NoWeb.h"
#include "Modules/Nuker.h"
#include "Modules/Phase.h"
#include "Modules/Reach.h"
#include "Modules/Scaffold.h"
#include "Modules/Spammer.h"
#include "Modules/Speed.h"
#include "Modules/StackableItem.h"
#include "Modules/Step.h"
#include "Modules/TimeChanger.h"
#include "Modules/Timer.h"
#include "Modules/Tower.h"
#include "Modules/Tracer.h"
#include "Modules/TriggerBot.h"
#include "Modules/Xray.h"
#include "Modules/NightMode.h"
#include "Modules/NoSwing.h"
#include "Modules/CubeGlide.h"
#include "Modules/AirStuck.h"
#include "Modules/Zoom.h"
#include "Modules/Teams.h"
#include "Modules/Nbt.h"
#include "Modules/Godmode.h"
#include "Modules/Freelook.h"
#include "Modules/NoHurtcam.h"
#include "Modules/AntiImmobile.h"
#include "Modules/FollowPathModule.h"
#include "Modules/NoPaintingCrash.h"
#include "Modules/Waypoints.h"
#include "Modules/Spider.h"
#include "Modules/Compass.h"
#include "Modules/Radar.h"
#include "Modules/VanillaPlus.h"
#include "Modules/Announcer.h"
#include "Modules/BlockEsp.h"
#include "Modules/CreativeFly.h"
#include "Modules/CrystalAuraWTA.h"
#include "Modules/CubeFly.h"
#include "Modules/CubeSpeed.h"
#include "Modules/Excavator.h"
#include "Modules/InsideAura.h"
#include "Modules/LongJump.h"
#include "Modules/MineplexBP.h"
#include "Modules/MineplexFly.h"
#include "Modules/NoClip.h"
#include "Modules/Placer.h"
#include "Modules/SignFucker.h"
#include "Modules/Twerk.h"
#include "Modules/selectionHighlight.h"
#include "Modules/HudEditor.h"
#include "Modules/BoatSpeed.h"
#include "Modules/RiptideFly.h"
#include "Modules/ViewModel.h"
#include "Modules/FastPlace.h"
#include "Modules/Welcome.h"
#include "Modules/KeyStrokes.h"
#include "Modules/ArrayList.h"
#include "Modules/PlayerList.h"
#include "Modules/WaterMark.h"
#include "Modules/ArmourHud.h"
#include "Modules/Coordinates.h"
#include "Modules/ServerInfo.h"
#include "Modules/pvpResources.h"
#include "Modules/EntityFly.h"
#include "Modules/ReverseStep.h"
#include "Modules/EndermanLook.h"
#include "Modules/autoWalk.h"
#include "Modules/Breadcrums.h"
#include "Modules/Theme.h"


#ifdef _DEBUG
#include "Modules/PacketLogger.h"
#include "Modules/TestModule.h"
#include "Modules/LogMessage.h"
#endif


class ModuleManager {
private:
	GameData* gameData;
	std::vector<std::shared_ptr<IModule>> moduleList;
	bool initialized = false;
	std::shared_mutex moduleListMutex;

public:
	~ModuleManager();
	ModuleManager(GameData* gameData);
	void initModules();
	void disable();
	void onLoadConfig(void* conf);
	void onSaveConfig(void* conf);
	void onTick(C_GameMode* gameMode);
	void onPreTick(C_GameMode* gameMode);
	void onAttack(C_Entity* attackedEnt);
	void onOptionsTick(C_Option** optionList);

	void onKeyUpdate(int key, bool isDown);
	void onPreRender(C_MinecraftUIRenderContext* renderCtx);
	void onPostRender(C_MinecraftUIRenderContext* renderCtx);
	void onLevelRender();
	void onMove(C_MoveInputHandler* handler);
	void onSendPacket(C_Packet*);

	std::shared_lock<std::shared_mutex> lockModuleList() { return std::shared_lock(this->moduleListMutex); }
	std::unique_lock<std::shared_mutex> lockModuleListExclusive() { return std::unique_lock(this->moduleListMutex); }
	
	std::shared_mutex* getModuleListLock() { return &this->moduleListMutex; }

	bool isInitialized() { return initialized; };
	std::vector<std::shared_ptr<IModule>>* getModuleList();

	int getModuleCount();
	int getEnabledModuleCount();

	/*
	 *	Use as follows: 
	 *		IModule* mod = moduleMgr.getModule<NoKnockBack>(); 
	 *	Check for nullptr directly after that call, as Hooks::init is called before ModuleManager::initModules !	
	 */
	template <typename TRet>
	TRet* getModule() {
		if (!isInitialized())
			return nullptr;
		auto lock = this->lockModuleList();
		for (auto pMod : moduleList) {
			if (auto pRet = dynamic_cast<typename std::remove_pointer<TRet>::type*>(pMod.get())){
				
				return pRet;
			}
		}
		return nullptr;
	};

	// Dont Use this functions unless you absolutely need to. The function above this one works in 99% of cases
	std::optional<std::shared_ptr<IModule>> getModuleByName(const std::string name) {
		if (!isInitialized())
			return nullptr;
		std::string nameCopy = name;
		std::transform(nameCopy.begin(), nameCopy.end(), nameCopy.begin(), ::tolower);
		
		auto lock = this->lockModuleList();
		for (std::vector<std::shared_ptr<IModule>>::iterator it = this->moduleList.begin(); it != this->moduleList.end(); ++it) {
			std::shared_ptr<IModule> mod = *it;
			std::string modNameCopy = mod->getRawModuleName();
			std::transform(modNameCopy.begin(), modNameCopy.end(), modNameCopy.begin(), ::tolower);
			if (modNameCopy == nameCopy)
				return std::optional<std::shared_ptr<IModule>>(mod);
		}
		return std::optional<std::shared_ptr<IModule>>();
	}
};

extern ModuleManager* moduleMgr;
