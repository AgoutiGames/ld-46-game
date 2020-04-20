<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="stage" tilewidth="100" tileheight="40" tilecount="8" columns="2">
 <image source="stage.png" width="200" height="160"/>
 <tile id="0" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="Stage1Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="id" value="stage1"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Stage1Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="0" duration="300"/>
   <frame tileid="1" duration="300"/>
  </animation>
 </tile>
 <tile id="2" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="Stage2Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="id" value="stage2"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="3" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Stage2Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="2" duration="300"/>
   <frame tileid="3" duration="300"/>
  </animation>
 </tile>
 <tile id="4" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="Stage3Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="id" value="stage3"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="5" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Stage3Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="4" duration="300"/>
   <frame tileid="5" duration="300"/>
  </animation>
 </tile>
 <tile id="6" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="Stage4Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="id" value="stage4"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="7" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Stage4Button"/>
   <property name="ANIMATION_TYPE" value="CLICK"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="6" duration="300"/>
   <frame tileid="7" duration="300"/>
  </animation>
 </tile>
</tileset>
