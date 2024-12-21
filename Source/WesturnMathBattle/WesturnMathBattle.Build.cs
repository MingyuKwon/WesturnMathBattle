// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WesturnMathBattle : ModuleRules
{
	public WesturnMathBattle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
