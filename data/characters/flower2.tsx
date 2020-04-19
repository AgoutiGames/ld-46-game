<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="flower2" tilewidth="16" tileheight="16" tilecount="6" columns="6">
 <image source="flower2.png" width="96" height="16"/>
 <tile id="0">
  <objectgroup draworder="index" id="2">
   <object id="1" x="3" y="9" width="10" height="7"/>
   <object id="2" name="WATER" x="3" y="0" width="10" height="9"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="BlueFlower"/>
   <property name="ANIMATION_TYPE" value="GROW1"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="5" duration="200"/>
   <frame tileid="4" duration="200"/>
   <frame tileid="3" duration="200"/>
   <frame tileid="2" duration="200"/>
   <frame tileid="1" duration="200"/>
   <frame tileid="0" duration="200"/>
  </animation>
 </tile>
</tileset>
