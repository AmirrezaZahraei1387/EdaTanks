//
// Created by KAVOSH on 10/30/2023.
//
#ifndef EDATANKS__TANK_REP_H
#define EDATANKS__TANK_REP_H

enum class STATE_OBJ{
    DIED,
    ALIVE
};


enum class BullHOLDER_STATE{
    EMPTY,
    HAVES
};

class TankEngine{
public:
    explicit TankEngine(int health, int max_speed):
    current_health_p{health},
    max_sp_p{max_speed}
    {
        def_state();
    }

    int current_health() const{return current_health_p;}
    int max_sp() const{return max_sp_p;}
    int current_sp() const{return current_health_p;}
    STATE_OBJ state_obj() const{return stateObj;}

    void dec_inc_sp(int value)
    {
        if(current_sp_p + value <= max_sp_p
        || current_sp_p + value >= 0){
            current_sp_p += value;
        }
    }

    void harm_engine(int value){

        if (current_health_p + value >=0 &&
        current_health_p + value <=current_health_p){
            current_health_p += value;
        }

        def_state();
    }


private:

    void def_state(){
        if (current_health_p == 0){
            stateObj = STATE_OBJ::DIED;
        }else{
            stateObj = STATE_OBJ::ALIVE;
        }
    }

    int current_health_p;

    STATE_OBJ stateObj{};
    int max_sp_p;
    int current_sp_p{0};
};

class TankBulletHolder{
public:
    explicit TankBulletHolder(int overall_h, int engine_h, int bull_num, int max_bull)
    : overall_health_d_p{overall_h},
      engine_health_d_p{engine_h},
      bullet_num_p{bull_num},
      max_bullet_num{max_bull}
    {
        def_state();
    }

    int overall_health() const{return overall_health_d_p;}
    int engine_health() const{return engine_health_d_p;}
    int bullet_num() const{return bullet_num_p;}
    BullHOLDER_STATE bullh_state() const{return bullHolderState;}

    void shoot()
    {
        if (bullHolderState == BullHOLDER_STATE::HAVES){
            bullet_num_p -= 1;
        }
        def_state();
    }

    void add_amu(int value){
        if(value + bullet_num_p <= max_bullet_num){
            bullet_num_p += value;
        }
    }
private:

    void def_state(){
        if (bullet_num_p == 0){
            bullHolderState = BullHOLDER_STATE::EMPTY;
        }else{
            bullHolderState = BullHOLDER_STATE::HAVES;
        }
    }

    int overall_health_d_p;
    int engine_health_d_p;

    BullHOLDER_STATE bullHolderState;
    int bullet_num_p;
    int max_bullet_num;
};

struct TankRepresentor{
    int x_d;
    int y_d;
    int a_d;
    int h_d;

    TankBulletHolder tankBulletHolder;
    TankEngine tankEngine;
};

#endif //EDATANKS__TANK_REP_H
