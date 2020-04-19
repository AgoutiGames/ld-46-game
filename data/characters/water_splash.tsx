<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="water_splash" tilewidth="16" tileheight="16" tilecount="6" columns="6">
 <image source="water_splash.png" width="96" height="16"/>
 <tile id="0" type="ACTOR_TEMPLATE">
  <properties>
   <property name="ACTOR_NAME" value="WaterSplash"/>
   <property name="ANIMATION_TYPE" value="SPLASH"/>
   <property name="type" value="Effect"/>
  </properties>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="WaterSplash"/>
   <property name="ANIMATION_TYPE" value="SPLASH"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="5" duration="1"/>
   <frame tileid="0" duration="100"/>
   <frame tileid="1" duration="100"/>
   <frame tileid="2" duration="100"/>
   <frame tileid="0" duration="100"/>
   <frame tileid="3" duration="100"/>
   <frame tileid="4" duration="100"/>
  </animation>
 </tile>
</tileset>
