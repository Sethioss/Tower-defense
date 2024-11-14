using UnrealBuildTool;

public class Abilities : ModuleRules

{
    public Abilities(ReadOnlyTargetRules Target) : base(Target)
    {

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "LightweightAbilitySystem"});

    }

}