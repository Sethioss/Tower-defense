using UnrealBuildTool;

public class LightweightAbilitySystem : ModuleRules

{
    public LightweightAbilitySystem(ReadOnlyTargetRules Target) : base(Target)
    {

        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});

    }

}