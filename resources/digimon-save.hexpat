#pragma allow_edits
#pragma loop_limit 0x2001

#include <std/mem.pat>
#include <std/io.pat>
#include <std/math.pat>

/**
 * This ImHex pattern maps the contents of the PS1 Digimon World 1 (USA) save file
 * It also optionally provides and writes the replacement checksum for the save. This 
 * is needed for the PS1 to run the save file. Enable the WRITE_CHECKSUM flag to set 
 * the checksum at the correct address.
 * 
 * WARNING: Always take a backup of your saves before messing with them!
 */

bool GENERATE_CHECKSUM in;
bool WRITE_CHECKSUM in;

bitfield MasteredMoves {
    // fire
    fire_tower: 1;
    prominence_beam: 1;
    spit_fire: 1;
    red_inferno: 1;
    magma_bomb: 1;
    heat_laser: 1;
    infinity_burn: 1;
    meltdown: 1;
    // air
    thunder_justice: 1;
    spinning_shot: 1;
    electric_cloud: 1;
    megalo_spark: 1;
    static_elect: 1;
    wind_cutter: 1;
    confused_storm: 1;
    hurricane: 1;
    // ice
    giga_freeze: 1;
    ice_statue: 1;
    winter_blast: 1;
    ice_needle: 1;
    water_blit: 1;
    aqua_magic: 1;
    aurora_freeze: 1;
    tear_drop: 1;
    // mech
    power_crane: 1;
    all_range_beam: 1;
    metal_sprinter: 1;
    pulse_laser: 1;
    delete_program: 1;
    dg_dimension: 1;
    full_potential: 1;
    reverse_prog: 1;
    // earth
    poison_powder: 1;
    bug: 1;
    mass_morph: 1;
    insect_plague: 1;
    charm_perfume: 1;
    poison_claw: 1;
    danger_sting: 1;
    green_trap: 1;
    // battle
    tremar: 1;
    muscle_charge: 1;
    war_cry: 1;
    sonic_jab: 1;
    dynamite_kick: 1;
    counter: 1;
    megaton_punch: 1;
    buster_dive: 1;
    // filth
    odor_spray: 1; // NOTE: for some reason these seem wrong
    poop_spd_toss: 1;
    big_poop_toss: 1;
    big_rnd_toss: 1;
    poop_rnd_toss: 1;
    rnd_spd_toss: 1;
    horizontal_kick: 1;
    ult_poop_hell: 1;
    // unkn
    a: 1;
    b: 1;
    c: 1;
    d: 1;
    e: 1;
    f: 1;
    g: 1;
    h: 1;
};


// The Digimon World save block starts with the same title each time
u64 bytes = std::mem::find_sequence(0, 0x53, 0x43, 0x13, 0x01, 0x82, 0x63, 0x82, 0x89); // This could be longer???
u64 Title @ bytes; 

u32 isNewGame @ bytes + (128 * 4); // Save data starts after 4 frames
u16 bits @ bytes + 0x03B4;
u16 digimon_type @ bytes + 0x03B8;
u16 remaining_life @ bytes + 0x03E0 + 0x48; // Does this represent hours?
u16 age @ bytes + 0x03E0 + 0x4A; // in days
u16 care_mistakes @ bytes + 0x03E0 + 0x52;
u16 weight @ bytes + 0x03E0 + 0x42;
u16 battles @ bytes + 0x03E0 + 0x54;
u16 happiness @ bytes + 0x03E0 + 0x2A;
u16 discipline @ bytes + 0x03E0 + 0x28;
u16 virus_bar @ bytes + 0x03E0 + 0x1E; // Out of 100?
MasteredMoves mastered_moves @ bytes + 0x03BC;
u16 offense @ bytes + 0x0470;
u16 defense @ bytes + 0x0470 + 0x02;
u16 speed @ bytes + 0x0470 + 0x04;
u16 brains @ bytes + 0x0470 + 0x06;
u32 tech_prio @ bytes + 0x0470 + 0x08;
u32 tech_equipped @ bytes + 0x0470 + 0x0C;
u16 max_hp @ bytes + 0x0470 + 0x10;
u16 max_mp @ bytes + 0x0470 + 0x12;
u16 curr_hp @ bytes + 0x0470 + 0x14;
u16 curr_mp @ bytes + 0x0470 + 0x16;

char tamer_name[20] @ bytes + 0x0667;
char digimon_name[20] @ bytes + 0x067B;
u8 lives_left @ bytes + 0x068F;
u8 tamer_level @  bytes + 0x0690;

fn reverseByteOrder(u32 num) {
    u32 byte0 = (num & 0x000000FF) << 24;
    u32 byte1 = (num & 0x0000FF00) << 8;
    u32 byte2 = (num & 0x00FF0000) >> 8;
    u32 byte3 = (num & 0xFF000000) >> 24;
    return byte0 | byte1 | byte2 | byte3;
};

if (GENERATE_CHECKSUM) {
    u8 save[0x2000] @ bytes;
    
    save[0x06FC] = 0x00;
    save[0x06FD] = 0x00;
    save[0x06FE] = 0x00;
    save[0x06FF] = 0x00;
    
    u32 sum = 0;
    for (u128 i = 0x200, i < 0x10FF+1, i += 1) {
        sum = sum+save[i];
    }
    
    std::print("Checksum: 0x{:08X}", reverseByteOrder(sum));
    std::print("--------------------");
    
    if (WRITE_CHECKSUM) {
        save[0x06FC] = reverseByteOrder(sum) >> 24;
        save[0x06FD] = reverseByteOrder(sum) >> 16;
        save[0x06FE] = reverseByteOrder(sum) >> 8;
        save[0x06FF] = reverseByteOrder(sum) >> 0;
    }
};