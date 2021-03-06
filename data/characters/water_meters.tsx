<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="water_meters" tilewidth="16" tileheight="16" tilecount="11" columns="11">
 <image source="water_meters.png" width="176" height="16"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="DefaultWaterMeter"/>
   <property name="ANIMATION_TYPE" value="DEPLETE"/>
   <property name="type" value="WaterMeter"/>
  </properties>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="DefaultWaterMeter"/>
   <property name="ANIMATION_TYPE" value="DEPLETE"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="10" duration="200"/>
   <frame tileid="9" duration="200"/>
   <frame tileid="8" duration="200"/>
   <frame tileid="7" duration="200"/>
   <frame tileid="6" duration="200"/>
   <frame tileid="5" duration="200"/>
   <frame tileid="4" duration="200"/>
   <frame tileid="3" duration="200"/>
   <frame tileid="2" duration="200"/>
   <frame tileid="1" duration="200"/>
   <frame tileid="0" duration="200"/>
  </animation>
 </tile>
</tileset>
