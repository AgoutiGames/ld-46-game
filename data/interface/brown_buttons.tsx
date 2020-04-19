<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="brown_buttons" tilewidth="100" tileheight="40" tilecount="6" columns="2">
 <image source="brown_buttons.png" width="200" height="120"/>
 <tile id="0" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="HowToButton"/>
   <property name="ANIMATION_TYPE" value="HOVER"/>
   <property name="id" value="HowTo"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="HowToButton"/>
   <property name="ANIMATION_TYPE" value="HOVER"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="0" duration="200"/>
   <frame tileid="1" duration="200"/>
  </animation>
 </tile>
 <tile id="2" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="QuitButton2"/>
   <property name="ANIMATION_TYPE" value="HOVER"/>
   <property name="id" value="Quit"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="3" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="QuitButton2"/>
   <property name="ANIMATION_TYPE" value="HOVER"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="2" duration="200"/>
   <frame tileid="3" duration="200"/>
  </animation>
 </tile>
 <tile id="4" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="StartButton2"/>
   <property name="ANIMATION_TYPE" value="HOVER"/>
   <property name="id" value="Start"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="40"/>
  </objectgroup>
 </tile>
 <tile id="5" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="StartButton2"/>
   <property name="ANIMATION_TYPE" value="HOVER"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="4" duration="200"/>
   <frame tileid="5" duration="200"/>
  </animation>
 </tile>
</tileset>
