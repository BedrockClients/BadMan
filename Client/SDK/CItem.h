#pragma once
//#include "Tag.h"
#include <memory>

#include "../Utils/HMath.h"
#include "../Utils/Utils.h"
#include "TextHolder.h"

class CompoundTag;
class Tag;
class C_BlockLegacy;
class C_BlockSource;
class C_Block;
class C_Entity;
class C_ItemStack;
class C_ItemStackBase;
class C_ScreenContext;
class C_ItemRenderer;
class C_ClientInstance;
class MinecraftGame;

class C_BaseActorRenderContext {
private:
	char pad_0x0[0x58];  //0x0000
public:
	C_ItemRenderer* renderer;  //0x0058
private:
	char pad_0x50[0x238];  //0x60
public:
	C_BaseActorRenderContext(C_ScreenContext* ScreenCtx, C_ClientInstance* client, MinecraftGame* game);
};

class C_ItemRenderer {
public:
	void renderGuiItemNew(C_BaseActorRenderContext* BaseActorRenderCtx, C_ItemStack* item, MinecraftGame* game, float x, float y, float opacity, float scale, bool isEnchanted);
	void renderGuiItemInChunk(C_BaseActorRenderContext* BaseActorRenderCtx, C_ItemStack* item, float x, float y, float opacity, float scale, bool isEnchanted, int mode);
};

class C_Item {
private:
	char pad_0028[136];  //0x0028
public:
	int16_t maxStackSize;  //0x0090
	int16_t itemId;        //0x0092
private:
	char pad_0094[4];  //0x0094
public:
	TextHolder tileName;  //0x0098
private:
	char pad_00B8[8];  //0x00B8
public:
	TextHolder name;  //0x00C0
private:
	char pad_00E0[8];  //0x00E0
public:
	TextHolder isFrom;  //0x00E8
private:
	char pad_0108[80];  //0x0108
public:
	int16_t duration;  //0x0158

	/*
private:
	char pad_0x0008[0x62];  //0x8
public:
	uint16_t itemId;  //0x6A
private:
	char pad_0x00072[0x4];  //0x6C
public:
	TextHolder tileName;  //0x70
	TextHolder name;      //0x90
private:
	char pad_0x0B8[0x4C];  //0xB0
public:
	int duration;  //0xFC*/
private:
	virtual __int64 destructor();
	virtual __int64 tearDown(void);
	virtual __int64 getMaxUseDuration(__int64 const*) const;
	virtual __int64 getMaxUseDuration(C_ItemStack const*) const;

public:
	virtual bool isExperimental(__int64 const*) const;
	virtual bool returnFalse();
	virtual void setMaxStackSize(unsigned char);
	virtual void setCategory(int);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped(void);
	virtual void setUseAnimation(int);
	virtual void setMaxUseDuration(int);
	virtual void setRequiresWorldBuilder(bool);
	virtual void setExplodable(bool);
	virtual void setFireResistant(bool);
	virtual void setIsGlint(bool);
	virtual void setShouldDespawn(bool);

private:
	virtual __int64 getC_BlockShape(void) const;

public:
	virtual bool canBeDepleted(void) const;
	virtual bool canDestroySpecial(C_Block const&) const;

private:
	virtual __int64 get__int64DataForAuxValue(int) const;

public:
	virtual bool isStackedByData(void) const;

public:
	virtual __int64 getMaxDamage(void) const;
	virtual int getAttackDamage(void) const;

public:
	virtual bool isHandEquipped(void) const;
	virtual bool _isArmor(void) const;
	inline bool isArmor() {
		return Utils::CallVFunc<8, bool>(this);
	}
	virtual bool isDye(void) const;
	virtual bool isFertilizer(int) const;
	virtual bool isGlint(C_ItemStack const&) const;
	virtual bool isThrowable(void) const;
	virtual bool isPattern(void) const;

private:
	virtual __int64 showsDurabilityInCreative(void) const;

public:
	virtual bool isWearableThroughLootTable(C_ItemStack const&) const;
	virtual bool canDestroyInCreative(void) const;
	virtual bool isDestructive(int) const;
	virtual bool isLiquidClipItem(int) const;

private:
	virtual bool requiresInteract();
	virtual __int64 appendFormattedHovertext(C_ItemStack const&, __int64&, std::string&, bool) const;

public:
	virtual bool isValidRepairItem(C_ItemStack const&, C_ItemStack const&) const;

public:
	virtual __int64 getEnchantSlot(void) const;
	virtual __int64 _getEnchantValue(void) const;
	virtual int _getArmorValue(void) const;

	inline int getArmorValue(void) {
		return Utils::CallVFunc<0x38, int>(this);
	}

	inline int getEnchantValue(void) {
		return Utils::CallVFunc<0x37, int>(this);
	}

public:
	virtual bool isComplex(void) const;
	virtual bool isValidAuxValue(int) const;

public:
	virtual __int64 getDamageChance(int) const;
	virtual __int64 uniqueAuxValues(void) const;

public:
	virtual bool isMultiColorTinted(C_ItemStack const&) const;

private:
	virtual __int64 getColor(C_ItemStack const&) const;
	virtual __int64 getBaseColor(C_ItemStack const&) const;
	virtual __int64 getSecondaryColor(C_ItemStack const&) const;
	virtual __int64 saveAdditionalData(C_ItemStack const&, __int64&) const;
	virtual __int64 readAdditionalData(C_ItemStack&, __int64 const&) const;

	virtual bool isTintable(void) const;
	virtual __int64 buildIdAux(short, const CompoundTag*);
	virtual __int64 buildDescriptor(short, const CompoundTag*);

public:
	virtual C_ItemStack* use(C_ItemStack*, C_Entity*) const;

private:
	virtual __int64 dispense(C_BlockSource&, __int64&, int, vec3_t const&, unsigned char) const;
	virtual __int64 useTimeDepleted(C_ItemStack&, __int64*, C_Entity*) const;
	virtual __int64 releaseUsing(C_ItemStack&, C_Entity*, int) const;
	virtual __int64 getDestroySpeed(C_ItemStack const&, C_Block const&) const;
	virtual __int64 hurtEnemy(__int64&, __int64*, __int64*) const;
	virtual __int64 hurtEnemy(C_ItemStack&, __int64*, __int64*) const;
	virtual __int64 mineC_Block(__int64&, C_Block const&, int, int, int, C_Entity*) const;
	virtual __int64 mineC_Block(C_ItemStack&, C_Block const&, int, int, int, C_Entity*) const;
	virtual __int64 buildDescriptionId(C_ItemStack const&) const;
	virtual __int64 buildEffectDescriptionName(C_ItemStack const&) const;
	virtual __int64 buildCategoryDescriptionName(C_ItemStack const&) const;
	virtual __int64 readUserData(C_ItemStack&, __int64&, __int64&) const;
	virtual __int64 writeUserData(C_ItemStack const&, __int64&) const;

public:
	virtual int getMaxStackSize(void* itemDescriptor) const;

private:
	virtual __int64 inventoryTick(C_ItemStack&, __int64&, C_Entity&, int, bool) const;
	//virtual __int64 refreshedInContainer(C_ItemStack&, __int64&)const;
	virtual __int64 refreshedInContainer(__int64&, __int64&) const;
	virtual __int64 getCooldownType(void) const;
	virtual __int64 getCooldownTime(void) const;
	virtual __int64 fixupOnLoad(__int64&) const;
	virtual __int64 fixupOnLoad(C_ItemStack&) const;
	//virtual __int64 getDamageValue(C_ItemStack const&) const;
	virtual __int64 getDamageValue(__int64 const&) const;

public:
	virtual void setDamageValue(C_ItemStack&, short) const;
	//virtual void setDamageValue(__int64&, short) const;

private:
	virtual __int64 getInHandUpdateType(C_Entity const&, __int64 const&, __int64 const&, bool, bool) const;
	virtual __int64 getInHandUpdateType(C_Entity const&, C_ItemStack const&, C_ItemStack const&, bool, bool) const;

public:
	//virtual bool isSameItem(__int64 const&, __int64 const&) const;
	virtual bool isSameItem(C_ItemStack const&, C_ItemStack const&) const;

private:
	virtual __int64 getInteractText(C_Entity const&) const;
	virtual __int64 getAnimationFrameFor(__int64*, bool, C_ItemStack const*, bool) const;

public:
	virtual bool isEmissive(int) const;

private:
	virtual __int64 getIcon(int, int, bool) const;
	virtual __int64 getIconYOffset(void) const;

public:
	virtual void setIcon(std::string const&, int);
	virtual void setIcon(__int64 const&);
	virtual void setIconAtlas(__int64 const&);
	virtual bool canBeCharged(void) const;

private:
	virtual __int64 playSoundIncrementally(__int64 const&, __int64&) const;
	virtual __int64 playSoundIncrementally(C_ItemStack const&, __int64&) const;
	virtual __int64 getAuxValuesDescription(void) const;
	virtual __int64 _checkUseOnPermissions(C_Entity&, __int64&, unsigned char const&, vec3_ti const&) const;
	virtual __int64 _checkUseOnPermissions(C_Entity&, C_ItemStack&, unsigned char const&, vec3_ti const&) const;
	virtual __int64 _calculatePlacePos(__int64&, C_Entity&, unsigned char&, vec3_ti&) const;
	virtual __int64 _calculatePlacePos(C_ItemStack&, C_Entity&, unsigned char&, vec3_ti&) const;
	virtual __int64 _useOn(__int64&, C_Entity&, vec3_ti, unsigned char, float, float, float) const;
	virtual __int64 _useOn(C_ItemStack&, C_Entity&, vec3_ti, unsigned char, float, float, float) const;

public:
	bool isTool(void) {
		if (getAttackDamage() > 0) return true;           // Does Attack Damage
		if (itemId == 300 || itemId == 301) return true;  // Bow
		if (itemId == 299) return true;                   // Flint n Steel
		return false;
	}
	bool isFood(void) {
		if (itemId == 259 || itemId == 258) return true;                                                                      // Golden Apple
		if (itemId == 257) return true;                                                                                       // Apple
		if (itemId == 260) return true;                                                                                       // Mushroom Stew
		if (itemId == 261) return true;                                                                                       // Bread
		if (itemId == 262 || itemId == 263) return true;                                                                      // Porkchop
		if (itemId == 264 || itemId == 265 || itemId == 269 || itemId == 268 || itemId == 266 || itemId == 267) return true;  // Fish
		if (itemId == 271) return true;                                                                                       // Cookie
		if (itemId == 272) return true;                                                                                       // Melon
		if (itemId == 273 || itemId == 274) return true;                                                                      // Beef
		if (itemId == 275 || itemId == 276) return true;                                                                      // Chicken
		if (itemId == 279) return true;                                                                                       // Carrot
		if (itemId == 280 || itemId == 281) return true;                                                                      // Potato
		if (itemId == 284) return true;                                                                                       // Pumpkin Pie
		if (itemId == 288 || itemId == 289 || itemId == 290) return true;                                                     // Rabbit thing
		if (itemId == 540 || itemId == 541) return true;                                                                      // Mutton
		if (itemId == 558) return true;
		return false;
	}
	bool isBlock(void) {
		auto val = *reinterpret_cast<__int64***>(reinterpret_cast<__int64>(this) + 0x1D0);
		return val != nullptr && *val != nullptr;
	}
};

class C_ItemStack {
private:
	uintptr_t** vTable;  //0x0000
public:
	C_Item** item;     //0x08
	CompoundTag* tag;  //0x10
private:
	char pad_0x18[0xA];  //0x18
public:
	char count;  //0x22
private:
	char pad_0x1B[0x6D];  //0x23
public:
	C_ItemStack() {
		memset(this, 0x0, sizeof(C_ItemStack));
	}

	C_ItemStack(C_BlockLegacy& legacy, int count) {
		memset(this, 0x0, sizeof(C_ItemStack));
		reinit(legacy, count);
	}

	C_ItemStack(C_Item& item, int count, int itemData) {
		memset(this, 0x0, sizeof(C_ItemStack));
		reinit(item, count, itemData);
	}

	C_ItemStack(C_ItemStack const& src);

	C_ItemStack(Tag const& tag);

	void fromTag(Tag const& tag);

	void save(CompoundTag** tag);

	void setUserData(std::unique_ptr<Tag> tag);

	bool isValid() {
		return this->item != nullptr && *this->item != nullptr;
	}

	inline C_Item* getItem() {
		return *this->item;
	}

	void reinit(C_BlockLegacy& legacy, int count);

	void reinit(C_Item& item, int count, int itemData);

	int getEnchantValue(int enchantId);

	bool isEnchanted() {
		int enchantValue = 0;
		for (int i = 0; i < 40; i++) {
			enchantValue = this->getEnchantValue(i);
		}
		if (enchantValue != 0)
			return true;
		else
			return false;
	}

	float getArmorValueWithEnchants() {
		if (!this->item || !(*this->item)->isArmor())
			return 0;

		return (float)(((*this->item)->getArmorValue() + ((this->getEnchantValue(0) * 1.5f    // Protection
														   + this->getEnchantValue(5) * 0.4f  // Thorns
														   + this->getEnchantValue(3) * 0.4f  // Blast Protection
														   + this->getEnchantValue(1) * 0.4f  // Fire Protection
														   + this->getEnchantValue(4) * 0.4f  // Projectile Protection
														   ))));
	}

	float getAttackingDamageWithEnchants() {
		if (!this->item)
			return 0;
		int sharpnessValue = this->getEnchantValue(9);
		return (*this->item)->getAttackDamage() + 1.25f * sharpnessValue;
	}

	void setShowPickUp(bool b) {
		*(bool*)(reinterpret_cast<__int64>(this) + 0x30) = b;
	}

private:
	inline void setVtable(void);
};

class C_ArmorItem : public C_Item {
private:
	char pad_0x108[0xF8];  //0x100
public:
	int ArmorSlot;  //0x1B8

	bool isHelmet() {
		return ArmorSlot == 0;
	}
	bool isChestplate() {
		return ArmorSlot == 1;
	}
	bool isLeggings() {
		return ArmorSlot == 2;
	}
	bool isBoots() {
		return ArmorSlot == 3;
	}
};

class ItemRegistry {
public:
	static C_Item*** getItemFromId(void* ptr, int itemId);
	static C_Item*** lookUpByName(void*, void*, TextHolder&);
};