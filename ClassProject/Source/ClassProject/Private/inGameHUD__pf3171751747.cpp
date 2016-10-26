#include "ClassProject.h"
#include "inGameHUD__pf3171751747.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Components/HorizontalBox.h"
#include "Runtime/UMG/Public/Components/HorizontalBoxSlot.h"
#include "Runtime/UMG/Public/Components/VerticalBox.h"
#include "Runtime/UMG/Public/Components/VerticalBoxSlot.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"
#include "inGameHUD__pf3171751747.h"
#include "Mage__pf3171751747.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/Visual.h"
#include "Runtime/CoreUObject/Classes/Object.h"
#include "Runtime/UMG/Public/Blueprint/WidgetNavigation.h"
#include "Runtime/SlateCore/Public/Input/NavigationReply.h"
#include "Runtime/UMG/Public/Slate/WidgetTransform.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/SlateCore/Public/Styling/SlateBrush.h"
#include "Runtime/SlateCore/Public/Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Layout/Margin.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/Engine/Classes/Vehicles/TireType.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/RecastNavMesh.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavFilters/NavigationQueryFilter.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontBulkData.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea_Obstacle.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/SlateCore/Public/Input/Events.h"
#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/Slate/Public/Widgets/Notifications/SProgressBar.h"
#include "Runtime/Engine/Classes/Slate/SlateBrushAsset.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyleAsset.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyleContainerBase.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyleContainerInterface.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyle.h"
#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/UMG/Public/Components/TextWidgetTypes.h"
#include "Runtime/Slate/Public/Framework/Text/TextLayout.h"
#include "Runtime/SlateCore/Public/Fonts/FontCache.h"
#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Sound/ReverbEffect.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/Engine/Classes/Engine/BlueprintCore.h"
#include "Runtime/Engine/Classes/GameFramework/SaveGame.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/Engine/Classes/Sound/SoundGroups.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineSession.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/ScriptViewportClient.h"
#include "Runtime/Engine/Classes/Engine/DebugDisplayProperty.h"
#include "Runtime/Engine/Classes/Engine/Console.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptActor.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsCollisionHandler.h"
#include "Runtime/Engine/Classes/AI/Navigation/AvoidanceManager.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationPath.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavMeshBoundsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/WorldSettings.h"
#include "Runtime/Engine/Classes/Sound/AudioVolume.h"
#include "Runtime/Engine/Classes/GameFramework/GameNetworkManager.h"
#include "Runtime/Engine/Classes/GameFramework/GameMode.h"
#include "Runtime/Engine/Classes/GameFramework/GameState.h"
#include "Runtime/Engine/Classes/GameFramework/GameSession.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPhysicsVolume.h"
#include "DmgTypeBP_Environmental__pf2398200284.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/UMG/Public/Animation/UMGSequencePlayer.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"
#include "Runtime/MovieScene/Public/MovieSceneSequence.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimationBinding.h"
#include "Runtime/MovieScene/Public/MovieScene.h"
#include "Runtime/MovieScene/Public/MovieSceneTrack.h"
#include "Runtime/MovieScene/Public/MovieSceneBinding.h"
#include "Runtime/MovieScene/Public/MovieScenePossessable.h"
#include "Runtime/MovieScene/Public/MovieSceneSpawnable.h"
#include "Runtime/UMG/Public/Blueprint/DragDropOperation.h"
#include "Runtime/Slate/Public/Widgets/Layout/Anchors.h"
#include "Runtime/UMG/Public/Components/NamedSlotInterface.h"
#include "Fireball__pf1471916900.h"
#include "FireballExplosion__pf3346625017.h"
#include "ThirdPerson_AnimBP__pf4153901168.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
UinGameHUD_C__pf3171751747::UinGameHUD_C__pf3171751747(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (UinGameHUD_C__pf3171751747::StaticClass() == GetClass()))
	{
		UinGameHUD_C__pf3171751747::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}
	
	bpv__Mage__pf = nullptr;
}
void UinGameHUD_C__pf3171751747::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
}
void UinGameHUD_C__pf3171751747::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	// List of all referenced converted classes
	extern UClass* Z_Construct_UClass_AMage_C__pf3171751747();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_AMage_C__pf3171751747());
	extern UClass* Z_Construct_UClass_AFireball_C__pf1471916900();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_AFireball_C__pf1471916900());
	extern UClass* Z_Construct_UClass_AFireballExplosion_C__pf3346625017();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_AFireballExplosion_C__pf3346625017());
	extern UClass* Z_Construct_UClass_UThirdPerson_AnimBP_C__pf4153901168();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_UThirdPerson_AnimBP_C__pf4153901168());
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__0 = NewObject<UWidgetTree>(InDynamicClass, UWidgetTree::StaticClass(), TEXT("WidgetTree"));
	InDynamicClass->MiscConvertedSubobjects.Add(__Local__0);
	auto __Local__1 = NewObject<UCanvasPanel>(__Local__0, UCanvasPanel::StaticClass(), TEXT("CanvasPanel_0"));
	static TWeakObjectPtr<UProperty> __Local__3{};
	const UProperty* __Local__2 = __Local__3.Get();
	if (nullptr == __Local__2)
	{
		__Local__2 = (UPanelWidget::StaticClass())->FindPropertyByName(FName(TEXT("Slots")));
		check(__Local__2);
		__Local__3 = __Local__2;
	}
	auto& __Local__4 = (*(__Local__2->ContainerPtrToValuePtr<TArray<UPanelSlot*> >((__Local__1), 0)));
	__Local__4 = TArray<UPanelSlot*> ();
	__Local__4.Reserve(1);
	auto __Local__5 = NewObject<UCanvasPanelSlot>(__Local__1, UCanvasPanelSlot::StaticClass(), TEXT("CanvasPanelSlot_1"));
	__Local__5->LayoutData.Offsets.Right = 369.412292f;
	__Local__5->LayoutData.Offsets.Bottom = 134.380081f;
	__Local__5->LayoutData.Anchors.Minimum = FVector2D(0.031250, 0.833333);
	__Local__5->LayoutData.Anchors.Maximum = FVector2D(0.031250, 0.833333);
	__Local__5->Parent = __Local__1;
	auto __Local__6 = NewObject<UHorizontalBox>(__Local__0, UHorizontalBox::StaticClass(), TEXT("HorizontalBox_26"));
	auto& __Local__7 = (*(__Local__2->ContainerPtrToValuePtr<TArray<UPanelSlot*> >((__Local__6), 0)));
	__Local__7 = TArray<UPanelSlot*> ();
	__Local__7.Reserve(2);
	auto __Local__8 = NewObject<UHorizontalBoxSlot>(__Local__6, UHorizontalBoxSlot::StaticClass(), TEXT("HorizontalBoxSlot_1"));
	__Local__8->Padding.Left = 5.000000f;
	__Local__8->Padding.Top = 5.000000f;
	__Local__8->Padding.Right = 5.000000f;
	__Local__8->Padding.Bottom = 5.000000f;
	__Local__8->Parent = __Local__6;
	auto __Local__9 = NewObject<UVerticalBox>(__Local__0, UVerticalBox::StaticClass(), TEXT("VerticalBox_1"));
	auto& __Local__10 = (*(__Local__2->ContainerPtrToValuePtr<TArray<UPanelSlot*> >((__Local__9), 0)));
	__Local__10 = TArray<UPanelSlot*> ();
	__Local__10.Reserve(2);
	auto __Local__11 = NewObject<UVerticalBoxSlot>(__Local__9, UVerticalBoxSlot::StaticClass(), TEXT("VerticalBoxSlot_1"));
	__Local__11->Padding.Left = 5.000000f;
	__Local__11->Padding.Top = 5.000000f;
	__Local__11->Padding.Right = 5.000000f;
	__Local__11->Padding.Bottom = 5.000000f;
	__Local__11->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__11->Parent = __Local__9;
	auto __Local__12 = NewObject<UEditableTextBox>(__Local__0, UEditableTextBox::StaticClass(), TEXT("EditableTextBox_1"));
	__Local__12->Text = FInternationalization::ForUseOnlyByLocMacroAndGraphNodeTextLiterals_CreateText(
	TEXT(" HP"), /* Literal Text */
	TEXT(""), /* Namespace */
	TEXT("5C68589544408A6838AA7CB4AFF45C03") /* Key */
	);
	__Local__12->WidgetStyle.Padding.Left = 9.000000f;
	__Local__12->WidgetStyle.Padding.Right = 9.000000f;
	__Local__12->WidgetStyle.Font.Size = 16;
	static TWeakObjectPtr<UProperty> __Local__14{};
	const UProperty* __Local__13 = __Local__14.Get();
	if (nullptr == __Local__13)
	{
		__Local__13 = (FSlateColor::StaticStruct())->FindPropertyByName(FName(TEXT("SpecifiedColor")));
		check(__Local__13);
		__Local__14 = __Local__13;
	}
	auto& __Local__15 = (*(__Local__13->ContainerPtrToValuePtr<FLinearColor >(&(__Local__12->WidgetStyle.BackgroundColor), 0)));
	__Local__15 = FLinearColor(0.945000, 0.137025, 0.257075, 0.318000);
	__Local__12->Slot = __Local__11;
	__Local__11->Content = __Local__12;
	__Local__10.Add(__Local__11);
	auto __Local__16 = NewObject<UVerticalBoxSlot>(__Local__9, UVerticalBoxSlot::StaticClass(), TEXT("VerticalBoxSlot_0"));
	__Local__16->Padding.Left = 5.000000f;
	__Local__16->Padding.Top = 5.000000f;
	__Local__16->Padding.Right = 5.000000f;
	__Local__16->Padding.Bottom = 5.000000f;
	__Local__16->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__16->Parent = __Local__9;
	auto __Local__17 = NewObject<UEditableTextBox>(__Local__0, UEditableTextBox::StaticClass(), TEXT("EditableTextBox_0"));
	__Local__17->Text = FInternationalization::ForUseOnlyByLocMacroAndGraphNodeTextLiterals_CreateText(
	TEXT("Stamina"), /* Literal Text */
	TEXT(""), /* Namespace */
	TEXT("6E4012CC4B7BBEAC66E774BDB31C6E28") /* Key */
	);
	__Local__17->WidgetStyle.Font.Size = 10;
	auto& __Local__18 = (*(__Local__13->ContainerPtrToValuePtr<FLinearColor >(&(__Local__17->WidgetStyle.BackgroundColor), 0)));
	__Local__18 = FLinearColor(0.565000, 0.509832, 0.201007, 0.397000);
	__Local__17->Slot = __Local__16;
	__Local__16->Content = __Local__17;
	__Local__10.Add(__Local__16);
	__Local__9->Slot = __Local__8;
	__Local__8->Content = __Local__9;
	__Local__7.Add(__Local__8);
	auto __Local__19 = NewObject<UHorizontalBoxSlot>(__Local__6, UHorizontalBoxSlot::StaticClass(), TEXT("HorizontalBoxSlot_0"));
	__Local__19->Padding.Left = 5.000000f;
	__Local__19->Padding.Top = 5.000000f;
	__Local__19->Padding.Right = 5.000000f;
	__Local__19->Padding.Bottom = 5.000000f;
	__Local__19->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__19->Parent = __Local__6;
	auto __Local__20 = NewObject<UVerticalBox>(__Local__0, UVerticalBox::StaticClass(), TEXT("VerticalBox_0"));
	auto& __Local__21 = (*(__Local__2->ContainerPtrToValuePtr<TArray<UPanelSlot*> >((__Local__20), 0)));
	__Local__21 = TArray<UPanelSlot*> ();
	__Local__21.Reserve(2);
	auto __Local__22 = NewObject<UVerticalBoxSlot>(__Local__20, UVerticalBoxSlot::StaticClass(), TEXT("VerticalBoxSlot_2"));
	__Local__22->Padding.Left = 5.000000f;
	__Local__22->Padding.Top = 5.000000f;
	__Local__22->Padding.Right = 5.000000f;
	__Local__22->Padding.Bottom = 5.000000f;
	__Local__22->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__22->Parent = __Local__20;
	auto __Local__23 = NewObject<UProgressBar>(__Local__0, UProgressBar::StaticClass(), TEXT("HPBar"));
	__Local__23->FillColorAndOpacity = FLinearColor(0.645000, 0.051600, 0.106709, 1.000000);
	__Local__23->Slot = __Local__22;
	__Local__22->Content = __Local__23;
	__Local__21.Add(__Local__22);
	auto __Local__24 = NewObject<UVerticalBoxSlot>(__Local__20, UVerticalBoxSlot::StaticClass(), TEXT("VerticalBoxSlot_3"));
	__Local__24->Padding.Left = 5.000000f;
	__Local__24->Padding.Top = 5.000000f;
	__Local__24->Padding.Right = 5.000000f;
	__Local__24->Padding.Bottom = 5.000000f;
	__Local__24->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__24->Parent = __Local__20;
	auto __Local__25 = NewObject<UProgressBar>(__Local__0, UProgressBar::StaticClass(), TEXT("StamBar"));
	__Local__25->FillColorAndOpacity = FLinearColor(0.720000, 0.567286, 0.088885, 1.000000);
	__Local__25->Slot = __Local__24;
	__Local__24->Content = __Local__25;
	__Local__21.Add(__Local__24);
	__Local__20->Slot = __Local__19;
	__Local__19->Content = __Local__20;
	__Local__7.Add(__Local__19);
	__Local__6->Slot = __Local__5;
	__Local__5->Content = __Local__6;
	__Local__4.Add(__Local__5);
	__Local__0->RootWidget = __Local__1;
}
void UinGameHUD_C__pf3171751747::GetSlotNames(TArray<FName>& SlotNames) const
{
	TArray<FName>  __Local__26;
	SlotNames.Append(__Local__26);
}
void UinGameHUD_C__pf3171751747::CustomNativeInitilize()
{
	TArray<UWidgetAnimation*>  __Local__27;
	TArray<FDelegateRuntimeBinding>  __Local__28;
	__Local__28.AddUninitialized(2);
	FDelegateRuntimeBinding::StaticStruct()->InitializeStruct(__Local__28.GetData(), 2);
	auto& __Local__29 = __Local__28[0];
	__Local__29.ObjectName = FString(TEXT("HPBar"));
	__Local__29.PropertyName = FName(TEXT("Percent"));
	__Local__29.FunctionName = FName(TEXT("Get_HPBar_Percent_0"));
	static TWeakObjectPtr<UProperty> __Local__31{};
	const UProperty* __Local__30 = __Local__31.Get();
	if (nullptr == __Local__30)
	{
		__Local__30 = (FDynamicPropertyPath::StaticStruct())->FindPropertyByName(FName(TEXT("Segments")));
		check(__Local__30);
		__Local__31 = __Local__30;
	}
	auto& __Local__32 = (*(__Local__30->ContainerPtrToValuePtr<TArray<FPropertyPathSegment> >(&(__Local__29.SourcePath), 0)));
	__Local__32 = TArray<FPropertyPathSegment> ();
	__Local__32.AddUninitialized(1);
	FPropertyPathSegment::StaticStruct()->InitializeStruct(__Local__32.GetData(), 1);
	auto& __Local__33 = __Local__32[0];
	__Local__33.Name = FName(TEXT("Get_HPBar_Percent_0"));
	auto& __Local__34 = __Local__28[1];
	__Local__34.ObjectName = FString(TEXT("StamBar"));
	__Local__34.PropertyName = FName(TEXT("Percent"));
	__Local__34.FunctionName = FName(TEXT("Get_StamBar_Percent_0"));
	static TWeakObjectPtr<UProperty> __Local__36{};
	const UProperty* __Local__35 = __Local__36.Get();
	if (nullptr == __Local__35)
	{
		__Local__35 = (FDynamicPropertyPath::StaticStruct())->FindPropertyByName(FName(TEXT("Segments")));
		check(__Local__35);
		__Local__36 = __Local__35;
	}
	auto& __Local__37 = (*(__Local__35->ContainerPtrToValuePtr<TArray<FPropertyPathSegment> >(&(__Local__34.SourcePath), 0)));
	__Local__37 = TArray<FPropertyPathSegment> ();
	__Local__37.AddUninitialized(1);
	FPropertyPathSegment::StaticStruct()->InitializeStruct(__Local__37.GetData(), 1);
	auto& __Local__38 = __Local__37[0];
	__Local__38.Name = FName(TEXT("Get_StamBar_Percent_0"));
	UWidgetBlueprintGeneratedClass::InitializeWidgetStatic(this, GetClass(), false, false, CastChecked<UWidgetTree>(CastChecked<UDynamicClass>(UinGameHUD_C__pf3171751747::StaticClass())->MiscConvertedSubobjects[0]), __Local__27, __Local__28);
}
void UinGameHUD_C__pf3171751747::PreSave(const class ITargetPlatform* TargetPlatform)
{
	Super::PreSave(TargetPlatform);
	TArray<FName> LocalNamedSlots;
	GetSlotNames(LocalNamedSlots);
	RemoveObsoleteBindings(LocalNamedSlots);
}
void UinGameHUD_C__pf3171751747::bpf__ExecuteUbergraph_inGameHUD__pf_0(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 2);
	b0l__CallFunc_GetPlayerCharacter_ReturnValue__pf = UGameplayStatics::GetPlayerCharacter(this, 0);
	b0l__K2Node_DynamicCast_AsMage__pf = Cast<AMage_C__pf3171751747>(b0l__CallFunc_GetPlayerCharacter_ReturnValue__pf);
	b0l__K2Node_DynamicCast_bSuccess__pf = (b0l__K2Node_DynamicCast_AsMage__pf != nullptr);;
	if (!b0l__K2Node_DynamicCast_bSuccess__pf)
	{
		return; //KCST_GotoReturnIfNot
	}
	// optimized KCST_UnconditionalGoto
	bpv__Mage__pf = b0l__K2Node_DynamicCast_AsMage__pf;
	return; // KCST_GotoReturn
}
void UinGameHUD_C__pf3171751747::bpf__Construct__pf()
{
	bpf__ExecuteUbergraph_inGameHUD__pf_0(2);
}
float  UinGameHUD_C__pf3171751747::bpf__Get_HPBar_Percent_0__pf()
{
	float bpp__ReturnValue__pf{};
	float bpv__CallFunc_GetHealthPercentage_Perc__pf{};
	if(IsValid(bpv__Mage__pf))
	{
		bpv__Mage__pf->bpf__GetHealthPercentage__pf(/*out*/ bpv__CallFunc_GetHealthPercentage_Perc__pf);
	}
	bpp__ReturnValue__pf = bpv__CallFunc_GetHealthPercentage_Perc__pf;
	return bpp__ReturnValue__pf;
}
float  UinGameHUD_C__pf3171751747::bpf__Get_StamBar_Percent_0__pf()
{
	float bpp__ReturnValue__pf{};
	float bpv__CallFunc_GetStamPercentage_Perc__pf{};
	if(IsValid(bpv__Mage__pf))
	{
		bpv__Mage__pf->bpf__GetStamPercentage__pf(/*out*/ bpv__CallFunc_GetStamPercentage_Perc__pf);
	}
	bpp__ReturnValue__pf = bpv__CallFunc_GetStamPercentage_Perc__pf;
	return bpp__ReturnValue__pf;
}
void UinGameHUD_C__pf3171751747::__StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Engine/EngineFonts/Roboto"), TEXT("Roboto"), TEXT("/Script/Engine"), TEXT("Font")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Props/MaterialSphere"), TEXT("MaterialSphere"), TEXT("/Script/Engine"), TEXT("StaticMesh")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Materials/M_Concrete_Grime"), TEXT("M_Concrete_Grime"), TEXT("/Script/Engine"), TEXT("Material")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Particles/P_Fire"), TEXT("P_Fire"), TEXT("/Script/Engine"), TEXT("ParticleSystem")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Particles/P_Explosion"), TEXT("P_Explosion"), TEXT("/Script/Engine"), TEXT("ParticleSystem")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Character/Mesh/UE4_Mannequin_Skeleton"), TEXT("UE4_Mannequin_Skeleton"), TEXT("/Script/Engine"), TEXT("Skeleton")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Start"), TEXT("ThirdPersonJump_Start"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_Jump"), TEXT("ThirdPerson_Jump"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Loop"), TEXT("ThirdPersonJump_Loop"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_IdleRun_2D"), TEXT("ThirdPerson_IdleRun_2D"), TEXT("/Script/Engine"), TEXT("BlendSpace1D")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"), TEXT("SK_Mannequin"), TEXT("/Script/Engine"), TEXT("SkeletalMesh")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
void UinGameHUD_C__pf3171751747::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
void UinGameHUD_C__pf3171751747::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Game/ThirdPersonCPP/Blueprints/Mage"), TEXT("Mage_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
		FBlueprintDependencyData(TEXT("/Game/ThirdPersonCPP/Fireball"), TEXT("Fireball_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
		FBlueprintDependencyData(TEXT("/Game/ThirdPersonCPP/StarterContent/Textures/FireballExplosion"), TEXT("FireballExplosion_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP"), TEXT("ThirdPerson_AnimBP_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
struct FRegisterHelper__UinGameHUD_C__pf3171751747
{
	FRegisterHelper__UinGameHUD_C__pf3171751747()
	{
		FConvertedBlueprintsDependencies::Get().RegisterClass(TEXT("/Game/ThirdPersonCPP/Blueprints/inGameHUD"), &UinGameHUD_C__pf3171751747::__StaticDependenciesAssets);
	}
	static FRegisterHelper__UinGameHUD_C__pf3171751747 Instance;
};
FRegisterHelper__UinGameHUD_C__pf3171751747 FRegisterHelper__UinGameHUD_C__pf3171751747::Instance;
#ifdef _MSC_VER
#pragma warning (pop)
#endif
