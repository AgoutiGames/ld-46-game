<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="player" tilewidth="32" tileheight="32" tilecount="6" columns="3">
 <image source="player.png" trans="ff00ff" width="96" height="64"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="FirstPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="DOWN"/>
   <property name="type" value="Gardener"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="10" y="27" width="12" height="5"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="FirstPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="DOWN"/>
  </properties>
 </tile>
 <tile id="3" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="FirstPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="UP"/>
  </properties>
 </tile>
 <tile id="4" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="FirstPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="LEFT"/>
  </properties>
 </tile>
 <tile id="5" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="FirstPlayer"/>
   <property name="ANIMATION_TYPE" value="WALK"/>
   <property name="DIRECTION" value="RIGHT"/>
  </properties>
 </tile>
</tileset>
