<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="water_pump" tilewidth="32" tileheight="32" tilecount="6" columns="6">
 <image source="water_pump.png" width="192" height="32"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="Pump"/>
   <property name="ANIMATION_TYPE" value="PUMP"/>
   <property name="type" value="WaterPump"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="12" y="26" width="8" height="5"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Pump"/>
   <property name="ANIMATION_TYPE" value="PUMP"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="0" duration="200"/>
   <frame tileid="1" duration="200"/>
   <frame tileid="2" duration="200"/>
   <frame tileid="3" duration="200"/>
   <frame tileid="4" duration="200"/>
   <frame tileid="5" duration="200"/>
  </animation>
 </tile>
</tileset>
