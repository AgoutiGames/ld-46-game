<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="multi" tilewidth="100" tileheight="40" tilecount="2" columns="1">
 <image source="multi.png" width="100" height="80"/>
 <tile id="0" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="MultiButton"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="id" value="multi"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="MultiButton"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="0" duration="300"/>
   <frame tileid="1" duration="300"/>
  </animation>
 </tile>
</tileset>
