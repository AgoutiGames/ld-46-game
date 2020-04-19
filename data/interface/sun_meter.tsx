<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="sun_meter" tilewidth="200" tileheight="32" tilecount="10" columns="1">
 <image source="sun_meter.png" width="200" height="320"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="SunMeter"/>
   <property name="ANIMATION_TYPE" value="FILL"/>
   <property name="type" value="WaterMeter"/>
  </properties>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="SunMeter"/>
   <property name="ANIMATION_TYPE" value="FILL"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
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
 <tile id="2">
  <animation>
   <frame tileid="0" duration="300"/>
   <frame tileid="1" duration="300"/>
   <frame tileid="2" duration="300"/>
   <frame tileid="3" duration="300"/>
   <frame tileid="4" duration="300"/>
   <frame tileid="5" duration="300"/>
   <frame tileid="6" duration="300"/>
   <frame tileid="7" duration="300"/>
   <frame tileid="9" duration="300"/>
  </animation>
 </tile>
</tileset>
