#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "GroupManager.h"
#include "Group.h"
#include "inifile/iniFile.h"
#include "ChatColor.h"
#include "Root.h"





typedef std::map< AString, cGroup* > GroupMap;





struct cGroupManager::sGroupManagerState
{
	GroupMap Groups;
};





cGroupManager::~cGroupManager()
{
	for( GroupMap::iterator itr = m_pState->Groups.begin(); itr != m_pState->Groups.end(); ++itr )
	{
		delete itr->second;
	}
	m_pState->Groups.clear();

	delete m_pState;
}





cGroupManager::cGroupManager()
	: m_pState( new sGroupManagerState )
{
	LOGD("-- Loading Groups --");
	cIniFile IniFile;
	if (!IniFile.ReadFile("groups.ini"))
	{
		LOGWARNING("Regenerating groups.ini, all groups will be reset");
		IniFile.AddHeaderComment(" This is the MCServer permissions manager groups file");
		IniFile.AddHeaderComment(" It stores all defined groups such as Administrators, Players, or Moderators");

		IniFile.SetValue("Owner", "Permissions", "*", true);
		IniFile.SetValue("Owner", "Color", "2", true);

		IniFile.SetValue("Moderator", "Permissions", "core.time,core.item,core.teleport,core.ban,core.unban,core.save-all,core.toggledownfall");
		IniFile.SetValue("Moderator", "Color", "2", true);
		IniFile.SetValue("Moderator", "Inherits", "Player", true);

		IniFile.SetValue("Player", "Permissions", "core.portal", true);
		IniFile.SetValue("Player", "Color", "f", true);
		IniFile.SetValue("Player", "Inherits", "Default", true);

		IniFile.SetValue("Default", "Permissions", "core.help,core.plugins,core.spawn,core.worlds,core.back,core.motd,core.build,core.locate,core.viewdistance", true);
		IniFile.SetValue("Default", "Color", "f", true);

		IniFile.WriteFile("groups.ini");
	}

	unsigned int NumKeys = IniFile.GetNumKeys();
	for (size_t i = 0; i < NumKeys; i++)
	{
		std::string KeyName = IniFile.GetKeyName( i );
		cGroup* Group = GetGroup( KeyName.c_str() );

		LOGD("Loading group: %s", KeyName.c_str() );

		Group->SetName(KeyName);
		AString Color = IniFile.GetValue(KeyName, "Color", "-");
		if ((Color != "-") && (Color.length() >= 1))
		{
			Group->SetColor(cChatColor::Color + Color[0]);
		}
		else
		{
			Group->SetColor(cChatColor::White);
		}

		AString Commands = IniFile.GetValue(KeyName, "Commands", "");
		if (!Commands.empty())
		{
			AStringVector Split = StringSplitAndTrim(Commands, ",");
			for (size_t i = 0; i < Split.size(); i++)
			{
				Group->AddCommand(Split[i]);
			}
		}

		AString Permissions = IniFile.GetValue(KeyName, "Permissions", "");
		if (!Permissions.empty())
		{
			AStringVector Split = StringSplitAndTrim(Permissions, ",");
			for (size_t i = 0; i < Split.size(); i++)
			{
				Group->AddPermission(Split[i]);
			}
		}

		std::string Groups = IniFile.GetValue(KeyName, "Inherits", "");
		if (!Groups.empty())
		{
			AStringVector Split = StringSplitAndTrim(Groups, ",");
			for (size_t i = 0; i < Split.size(); i++)
			{
				Group->InheritFrom(GetGroup(Split[i].c_str()));
			}
		}
	}
	LOGD("-- Groups Successfully Loaded --");
}





cGroup* cGroupManager::GetGroup( const AString & a_Name )
{
	GroupMap::iterator itr = m_pState->Groups.find( a_Name );
	if( itr != m_pState->Groups.end() )
	{
		return itr->second;
	}

	cGroup* Group = new cGroup();
	m_pState->Groups[a_Name] = Group;

	return Group;
}




