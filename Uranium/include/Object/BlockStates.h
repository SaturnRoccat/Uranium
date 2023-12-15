#pragma once
#include <string>
#include <array>
#include <vector>
namespace Uranium
{
	namespace Creation
	{
		namespace BlockStates
		{
            static std::vector<std::string> internalBlockStatesRep = {
                "propagule_stage",
                "can_summon",
                "bloom",
                "active",
                "item_frame_photo_bit",
                "candles",
                "lit",
                "multi_face_direction_bits",
                "big_dripleaf_head",
                "big_dripleaf_tilt",
                "growing_plant_age",
                "dripstone_thickness",
                "respawn_anchor_charge",
                "twisting_vines_age",
                "wall_connection_type_west",
                "wall_connection_type_south",
                "wall_connection_type_east",
                "wall_connection_type_north",
                "wall_post_bit",
                "weeping_vines_age",
                "honey_level",
                "block_light_level",
                "pillar_axis",
                "lever_direction",
                "coral_fan_direction",
                "composter_fill_level",
                "extinguished",
                "structure_block_type",
                "structure_void_type",
                "attachment",
                "coral_hang_type_bit",
                "stripped_bit",
                "hanging",
                "cauldron_liquid",
                "coral_color",
                "sea_grass_type",
                "chemistry_table_type",
                "double_plant_type",
                "prismarine_block_type",
                "wall_block_type",
                "huge_mushroom_bits",
                "stone_brick_type",
                "monster_egg_stone_type",
                "stone_slab_type4",
                "stone_slab_type3",
                "stone_slab_type2",
                "stone_slab_type",
                "flower_type",
                "tall_grass_type",
                "sandstone_type",
                "sponge_type",
                "new_leaf_type",
                "old_leaf_type",
                "deprecated",
                "chisel_type",
                "new_log_type",
                "old_log_type",
                "sand_type",
                "dirt_type",
                "stone_type",
                "wood_type",
                "stability_check",
                "stability",
                "bamboo_leaf_size",
                "bamboo_stalk_thickness",
                "coral_direction",
                "weirdo_direction",
                "ground_sign_direction",
                "cracked_state",
                "turtle_egg_count",
                "drag_down",
                "torch_facing_direction",
                "sapling_type",
                "item_frame_map_bit",
                "cluster_count",
                "dead_bit",
                "color_bit",
                "allow_underwater_bit",
                "vine_direction_bits",
                "upside_down_bit",
                "update_bit",
                "triggered_bit",
                "top_slot_bit",
                "toggle_bit",
                "suspended_bit",
                "repeater_delay",
                "redstone_signal",
                "rail_direction",
                "rail_data_bit",
                "powered_bit",
                "persistent_bit",
                "output_lit_bit",
                "output_subtract_bit",
                "open_bit",
                "occupied_bit",
                "kelp_age",
                "no_drop_bit",
                "moisturized_amount",
                "liquid_depth",
                "in_wall_bit",
                "infiniburn_bit",
                "head_piece_bit",
                "fill_level",
                "facing_direction",
                "explode_bit",
                "end_portal_eye_bit",
                "upper_block_bit",
                "door_hinge_bit",
                "disarmed_bit",
                "covered_bit",
                "conditional_bit",
                "button_pressed_bit",
                "brewing_stand_slot_c_bit",
                "brewing_stand_slot_b_bit",
                "brewing_stand_slot_a_bit",
                "bite_counter",
                "portal_axis",
                "attached_bit"
            };
            enum class BlockStates {
                propaguleStage         ,
                canSummon              ,
                bloom                  ,
                active                 ,
                itemFramePhotoBit      ,
                candles                ,
                lit                    ,
                multiFaceDirectionBits ,
                bigDripleafHead        ,
                bigDripleafTilt        ,
                growingPlantAge        ,
                dripstoneThickness     ,
                respawnAnchorCharge    ,
                twistingVinesAge       ,
                wallConnectionTypeWest ,
                wallConnectionTypeSouth,
                wallConnectionTypeEast ,
                wallConnectionTypeNorth,
                wallPostBit            ,
                weepingVinesAge        ,
                honeyLevel             ,
                blockLightLevel        ,
                pillarAxis             ,
                leverDirection         ,
                coralFanDirection      ,
                composterFillLevel     ,
                extinguished           ,
                structureBlockType     ,
                structureVoidType      ,
                attachment             ,
                coralHangTypeBit       ,
                strippedBit            ,
                hanging                ,
                cauldronLiquid         ,
                coralColor             ,
                seaGrassType           ,
                chemistryTableType     ,
                doublePlantType        ,
                prismarineBlockType    ,
                wallBlockType          ,
                hugeMushroomBits       ,
                stoneBrickType         ,
                monsterEggStoneType    ,
                stoneSlabType4         ,
                stoneSlabType3         ,
                stoneSlabType2         ,
                stoneSlabType          ,
                flowerType             ,
                tallGrassType          ,
                sandStoneType          ,
                spongeType             ,
                newLeafType            ,
                oldLeafType            ,
                deprecated             ,
                chiselType             ,
                newLogType             ,
                oldLogType             ,
                sandType               ,
                dirtType               ,
                stoneType              ,
                woodType               ,
                stabilityCheck         ,
                stability              ,
                bambooLeafSize         ,
                bambooStalkThickness   ,
                coralDirection         ,
                weirdoDirection        ,
                groundSignDirection    ,
                crackedState           ,
                turtleEggCount         ,
                dragDown               ,
                torchFacingDirection   ,
                saplingType            ,
                itemFrameMapBit        ,
                clusterCount           ,
                deadBit                ,
                colorBit               ,
                allowUnderwaterBit     ,
                vineDirectionBits      ,
                upsideDownBit          ,
                updateBit              ,
                triggeredBit           ,
                topSlotBit             ,
                toggleBit              ,
                suspendedBit           ,
                repeaterDelay          ,
                redstoneSignal         ,
                railDirection          ,
                railDataBit            ,
                poweredBit             ,
                persistentBit          ,
                outputLitBit           ,
                outputSubtractBit      ,
                openBit                ,
                occupiedBit            ,
                kelpAge                ,
                noDropBit              ,
                moisturizedAmount      ,
                liquidDepth            ,
                inWallBit              ,
                infiniburnBit          ,
                headPieceBit           ,
                fillLevel              ,
                facingDirection        ,
                explodeBit             ,
                endPortalEyeBit        ,
                upperBlockBit          ,
                doorHingeBit           ,
                disarmedBit            ,
                coveredBit             ,
                conditionalBit         ,
                buttonPressedBit       ,
                brewingStandSlotCBit   ,
                brewingStandSlotBBit   ,
                brewingStandSlotABit   ,
                biteCounter            ,
                portalAxis             ,
                attachedBit            ,
            };

            std::string getBlockStateName(BlockStates state)
            {
				return internalBlockStatesRep[static_cast<int>(state)];
			}
		}
	}
}