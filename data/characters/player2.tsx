<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="player" tilewidth="32" tileheight="32" tilecount="6" columns="3">
 <image source="player2.png" trans="ff00ff" width="96" height="64"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="SecondPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="DOWN"/>
   <property name="m_player_index" type="int" value="0"/>
   <property name="type" value="Gardener"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="10" y="27" width="12" height="5"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="SecondPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="DOWN"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" name="FILL" x="13" y="16" width="6" height="9"/>
   <object id="2" name="WATER" x="14" y="19" width="4" height="8"/>
  </objectgroup>
 </tile>
 <tile id="3" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="SecondPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="UP"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" name="FILL" x="14" y="16" width="4" height="6"/>
   <object id="2" name="WATER" x="14" y="10" width="4" height="10"/>
  </objectgroup>
 </tile>
 <tile id="4" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="SecondPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="LEFT"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" name="FILL" x="6" y="16" width="8" height="5"/>
   <object id="2" name="WATER" x="0" y="14" width="9" height="12"/>
  </objectgroup>
 </tile>
 <tile id="5" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="SecondPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="RIGHT"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" name="FILL" x="18" y="16" width="8" height="5"/>
   <object id="2" name="WATER" x="23" y="14" width="9" height="12"/>
  </objectgroup>
 </tile>
</tileset>
