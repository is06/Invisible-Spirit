Save
====

class is06::NEngine::NSave::CSave
---------------------------------

### Interface methods

* void loadPrimitiveInfo(irr::u8 slot);
* void load(irr::u8 slot);
* void save(irr::u8 slot);
* s32& getInteger(irr::u32 index);
* void setInteger(irr::u32 index, irr::s32 value);
* void incInteger(irr::u32 index, irr::s32 value);
* void decInteger(irr::u32 index, irr::s32 value);
* bool& getBoolean(irr::u32 index);
* void setBoolean(irr::u32 index, bool value);
* string& getString(irr::u32 index);
* void setString(irr::u32 index, const std::string& value);
* void earnTrophy(is06::NEngine::NGameplay::ETrophyIdentifier trophy);