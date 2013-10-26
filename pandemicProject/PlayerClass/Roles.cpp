/*
 * This is my Roles stub. The way I am thinking these functions
 * might be used is to have a check in the model to see what the
 * current player's role is, and then add that option to the UI
 * If it is an auto ability, then we will likely check the conditions
 * for the action in the model.
 */
#include <iostream>
#include "Deck.h"
#include <string>
#include "Player.h"
#include "City.h"
using namespace std;

void CPgetEventCard(Deck*);
void DmovePlayerToPlayerCity(Player*);
void DmovePlayerAsYourself(Player*);
void MtreatDisease(string);
void MautoCure();
void OEbuildResearchStation(City *);
void OEmove(City*);
bool QSautoContain();
void RgiveCityCard(Player*);
void Scure(string);

void CPgetEventCard(Deck* discard){
    
    /*      Contingency Planer Role ability
     * I think we talked about using a deck object
     * for the discard pile. If that is the case
     * we can just pass it, search it, and pick it
     * we also have to remove the card form the game
     */
    return;
}

void DmovePlayerToPlayerCity(Player* toMove){

    /*      Dispatcher Role Ability
     * Takes the player dispatcher wants to move as param
     * Asks the other player if it is OK to move
     * sets that players location to the new city
     *
     */
    return;
}

void DmovePlayerAsYourself(Player* toMove){

    /*      Dispatcher Role Ability
     * Takes the player dispatcher wants to move as param
     * Asks the other player if it is OK to move
     * I think to impliment we either set the
     * requested player as the current player,
     * or make a new PlayerMove object and then 
     * set the player as current player.
     * We will have to see how this effects the UI
     * and other aspects that use the current player
     * pointer
     */
    return;
}

void MtreatDisease(string color){

    /*      Medic Role Ability
     * Takes the color as a param even though
     * I am pretty sure there can only be one type of
     * disease cube per city. The actual action is simple
     * just clear all of the cubes instead of 1
     */

}

void MautoCure(){
    
    /*      Medic Role Ability
     * No parameters, conditions likely checked elsewhere.
     * This will simply remove all cubes of a cured
     * disease when a medic enters the city
     *
     */

}
void OEbuildResearchStation(Player* p){
  
    /*      Operations Expert Ability
     * Simply build an RS at the players current
     * location.
     */

}

void OEmove(City*){
    /*      Operations Expert Ability
     * This will take the city the OE wants to move
     * to as a param. Will prompt to pick a card to
     * discard.
     *
     */

}
bool QSautoContain(){
   
    /*      Quarantine Specialist Ability
     * Like the medic's Auto cure, the conditions for
     * this action (if the game attempts to add a disease)
     * will be checked elsewhere. This function will simply
     * return true if the QS is on or adjacent to the city
     * that the game trys to add a cube on to.
     */
    return false;
}
void RgiveCityCard(Player*){
    
    /*      Researcher Ability
     * This action can be done on anyone's turn
     * It is similar to share knowledge but without
     * needing the card to match. The recieving player will
     * be the parameter.
     */
}
void Scure(string){

    /*      scientist Ability
     * This one is pretty straight forward.
     * It is basically the cure disease function but
     * with a 4 card condition instead of 5
     */
}
