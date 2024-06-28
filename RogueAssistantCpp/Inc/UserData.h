#pragma once
#include "Defines.h"

#include <fstream>
#include <string>
#include <map>

class UserData
{
public:
	static bool DoesDirectoryExist(std::wstring const& path);
	static bool DoesFileExist(std::wstring const& path);

	static bool TryOpenReadFile(std::wstring const& path, std::fstream& outStream);
	static bool TryOpenWriteFile(std::wstring const& path, std::fstream& outStream, bool createIfMissing = true);
	static bool TryOpenAppendFile(std::wstring const& path, std::fstream& outStream, bool createIfMissing = true);

	static void Init();
	static void Update();

	static std::string GetSavedString(std::string const& key, std::string const& defaultValue = "");
	static void SetSavedString(std::string const& key, std::string const& value);

	static int GetSavedInt(std::string const& key, int defaultValue = 0);
	static void SetSavedInt(std::string const& key, int value);

private:
	static std::map<std::string, std::string> s_SavedValues;
	static bool s_PendingSavedValueChange;
};
