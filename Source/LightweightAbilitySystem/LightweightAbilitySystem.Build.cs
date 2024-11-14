using UnrealBuildTool;

public class LightweightAbilitySystem : ModuleRules

{
    public LightweightAbilitySystem(ReadOnlyTargetRules Target) : base(Target)
    {

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "Abilities"});

    }

}