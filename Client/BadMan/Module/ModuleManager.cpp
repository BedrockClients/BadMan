#include "ModuleManager.h"
#include "../../Utils/Logger.h"
#include "../../Utils/Json.hpp"

using json = nlohmann::json;

ModuleManager::ModuleManager(GameData* gameData) {
	this->gameData = gameData;
}

ModuleManager::~ModuleManager() {
	initialized = false;
	auto lock = this->lockModuleListExclusive();
	this->moduleList.clear();
}

void ModuleManager::initModules() {
	logF("Initializing modules");
	{
		auto lock = this->lockModuleListExclusive();

		this->moduleList.push_back(std::shared_ptr<IModule>(new HudModule()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new cps()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new R9J9ServerFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ShulkerExploit()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoEntityTrace()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AntiAnvil()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AltTheme()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Targethud()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Bps()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Background()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoEntityRender()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Surround()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoMiningTrace()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AntiHunger()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoEz()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new DvdLogo()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new fps()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new SessionInfo()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CrosshairPlus()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new InventoryView()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ElytraFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CrystalAuraOW()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NukkitNoFall()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoTrap()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Auto32k()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CustomSky()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ForceTotem()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new DeathCoords()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new TPAura()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Killaura()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ESP()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Jetpack()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Aimbot()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new TriggerBot()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ChestESP()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Velocity()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AirJump()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Step()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Glide()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new EditionFaker()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Phase()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Freecam()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoSprint()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Tracer()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new BowAimbot()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Scaffold()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoFall()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Blink()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Nuker()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new InstaBreak()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoPacket()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Speed()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Xray()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Fucker()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoSlowDown()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoTotem()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new InfiniteReach()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ClickGuiMod()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ChestStealer()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Fly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Hitbox()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Reach()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new FullBright()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AirSwim()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new InventoryMove()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new HighJump()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoWeb()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new FastLadder()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new StackableItem()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new FastEat()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Jesus()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoArmor()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ExtendedBlockReach()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoClicker()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NameTags()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Criticals()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Bhop()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Tower()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AntiVoid()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new MidClick()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Teleport()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoFriends()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Spammer()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ChestAura()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AntiBot()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new InventoryCleaner()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Derp()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Crasher()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CrystalAura()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Timer()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NightMode()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoSwing()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CubeGlide()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AirStuck()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Zoom()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Teams()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Nbt()));
		//this->moduleList.push_back(std::shared_ptr<IModule>(new Godmode()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Freelook()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AutoSneak()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoHurtcam()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new AntiImmobile()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new	NoPaintingCrash()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Waypoints()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new TimeChanger()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new	Spider()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new	Compass()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new	Radar()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new VanillaPlus()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Announcer()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new BlockEsp()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CreativeFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CrystalAuraWTA()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CubeFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new CubeSpeed()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Excavator()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new InsideAura()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new LongJump()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new MineplexBP()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new MineplexFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new NoClip()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Placer()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new SignFucker()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Twerk()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new selectionHighlight()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new HudEditor()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new BoatSpeed()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new RiptideFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ViewModel()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new FastPlace()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Welcome()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new KeyStrokes()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ArrayList()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new PlayerList()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new WaterMark()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ArmourHud()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Coordinates()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ServerInfo()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new pvpResources()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new EntityFly()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new ReverseStep()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new EndermanLook()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new autoWalk()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Breadcrums()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Theme()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new FollowPathModule()));

#ifdef _DEBUG
		this->moduleList.push_back(std::shared_ptr<IModule>(new PacketLogger()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new TestModule()));
		this->moduleList.push_back(std::shared_ptr<IModule>(new Logs()));
#endif

		// Sort modules alphabetically
		std::sort(moduleList.begin(), moduleList.end(), [](auto lhs, auto rhs) {
			auto current = lhs;
			auto other = rhs;
			return std::string{*current->getModuleName()} < std::string{*other->getModuleName()};
		});

		initialized = true;
	}
	
	this->getModule<HudModule>()->setEnabled(true);
	this->getModule<ClickGuiMod>()->setEnabled(false);
	this->getModule<AntiBot>()->setEnabled(true);
}

void ModuleManager::disable() {
	auto lock = this->lockModuleList();
	for (auto& mod : this->moduleList) {
		if (mod->isEnabled())
			mod->setEnabled(false);
	}
}

void ModuleManager::onLoadConfig(void* confVoid) {
	auto conf = reinterpret_cast<json*>(confVoid);
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& mod : this->moduleList) {
		mod->onLoadConfig(conf);
	}

	this->getModule<HudModule>()->setEnabled(true);
	this->getModule<ClickGuiMod>()->setEnabled(false);
	this->getModule<AntiBot>()->setEnabled(true);
}

void ModuleManager::onSaveConfig(void* confVoid) {
	auto conf = reinterpret_cast<json*>(confVoid);
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& mod : this->moduleList) {
		mod->onSaveConfig(conf);
	}
}

void ModuleManager::onOptionsTick(C_Option** optionList) {
	if (!isInitialized())
		return;

	auto lock = this->lockModuleList();

	for (auto& mod : this->moduleList) {
		if (mod->isEnabled() || mod->callWhenDisabled())
			mod->onOptionsTick(optionList);
	}
}

int logDelay = 0;

void ModuleManager::onTick(C_GameMode* gameMode) {
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& mod : this->moduleList) {
		if (mod->isEnabled() || mod->callWhenDisabled())
			mod->onTick(gameMode);
	}
}

void ModuleManager::onPreTick(C_GameMode* gameMode) {
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	//    mod->setEnabled(false);

	for (auto& mod : this->moduleList) {
		if (mod->isEnabled() || mod->callWhenDisabled())
			mod->onPreTick(gameMode);
	}
}

void ModuleManager::onAttack(C_Entity* attackEnt) {
	if (!isInitialized())
		return;

	auto lock = this->lockModuleList();
	for (auto& mod : this->moduleList) {
		if (mod->isEnabled() || mod->callWhenDisabled())
			mod->onAttack(attackEnt);
	}
}

void ModuleManager::onKeyUpdate(int key, bool isDown) {
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& mod : this->moduleList) {
		mod->onKeyUpdate(key, isDown);
	}
}

void ModuleManager::onPreRender(C_MinecraftUIRenderContext* renderCtx) {
	if (!isInitialized())
		return;
	auto mutex = this->lockModuleList();

	for (auto& mod : this->moduleList) {
		if (mod->isEnabled() || mod->callWhenDisabled())
			mod->onPreRender(renderCtx);
	}
}

void ModuleManager::onPostRender(C_MinecraftUIRenderContext* renderCtx) {
	if (!isInitialized())
		return;
	auto mutex = this->lockModuleList();

	for (auto& mod : this->moduleList) {
		if (mod->isEnabled() || mod->callWhenDisabled())
			mod->onPostRender(renderCtx);
	}
}

void ModuleManager::onSendPacket(C_Packet* packet) {
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& it : moduleList) {
		if (it->isEnabled() || it->callWhenDisabled())
			it->onSendPacket(packet);
	}
}

std::vector<std::shared_ptr<IModule>>* ModuleManager::getModuleList() {
	return &this->moduleList;
}

int ModuleManager::getModuleCount() {
	return (int)moduleList.size();
}

int ModuleManager::getEnabledModuleCount() {
	int i = 0;
	auto lock = this->lockModuleList();
	for (auto& it : moduleList) {
		if (it->isEnabled()) i++;
	}
	return i;
}
void ModuleManager::onMove(C_MoveInputHandler* hand) {
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& it : moduleList) {
		if (it->isEnabled() || it->callWhenDisabled())
			it->onMove(hand);
	}
}
void ModuleManager::onLevelRender() {
	if (!isInitialized())
		return;
	auto lock = this->lockModuleList();
	for (auto& it : moduleList) {
		if (it->isEnabled() || it->callWhenDisabled())
			it->onLevelRender();
	}
}

ModuleManager* moduleMgr = new ModuleManager(&g_Data);
