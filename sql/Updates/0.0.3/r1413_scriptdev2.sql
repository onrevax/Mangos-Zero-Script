DELETE FROM script_texts WHERE entry BETWEEN -1601024 AND -1601000;
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1601000,'This kingdom belongs to the Scourge! Only the dead may enter.',14075,1,0,0,'krikthir SAY_AGGRO'),
(-1601001,'???',14076,1,0,0,'krikthir SAY_KILL_1'),
(-1601002,'You were foolish to come.',14077,1,0,0,'krikthir SAY_KILL_2'),
(-1601003,'As Anub\'Arak commands!',14078,1,0,0,'krikthir SAY_KILL_3'),
(-1601004,'We are besieged. Strike out and bring back their corpses!',14079,1,0,0,'krikthir SAY_SEND_GROUP_1'),
(-1601005,'We must hold the gate. Attack! Tear them limb from limb!',14080,1,0,0,'krikthir SAY_SEND_GROUP_2'),
(-1601006,'The gate must be protected at all costs. Rip them to shreds!',14081,1,0,0,'krikthir SAY_SEND_GROUP_3'),
(-1601007,'Keep an eye on the tunnel. We must not let anyone through!',14082,1,0,0,'krikthir SAY_PREFIGHT_1'),
(-1601008,'I hear footsteps. Be on your guard.',14083,1,0,0,'krikthir SAY_PREFIGHT_2'),
(-1601009,'I sense the living. Be ready.',14084,1,0,0,'krikthir SAY_PREFIGHT_3'),
(-1601010,'They hunger.',14085,1,0,0,'krikthir SAY_SWARM_1'),
(-1601011,'Dinner time, my pets.',14086,1,0,0,'krikthir SAY_SWARM_2'),
(-1601012,'I should be grateful. But I long ago lost the capacity.',14087,1,0,0,'krikthir SAY_DEATH'),
(-1601013,'%s goes into a frenzy!',0,3,0,0,'krikthir EMOTE_FRENZY'),

(-1601014,'I was king of this empire once, long ago. In life I stood as champion. In death I returned as conqueror. Now I protect the kingdom once more. Ironic, yes?',14053,1,0,0,'anubarak SAY_INTRO'),
(-1601015,'Eternal agony awaits you!',14054,1,0,0,'anubarak SAY_AGGRO'),
(-1601016,'You shall experience my torment, first-hand!',14055,1,0,0,'anubarak SAY_KILL_1'),
(-1601017,'You have made your choice.',14056,1,0,0,'anubarak SAY_KILL_2'),
(-1601018,'Soon, the Master\'s voice will call to you.',14057,1,0,0,'anubarak SAY_KILL_3'),
(-1601019,'Come forth, my brethren. Feast on their flesh!',14058,1,0,0,'anubarak SAY_SUBMERGE_1'),
(-1601020,'Auum na-l ak-k-k-k, isshhh.',14059,1,0,0,'anubarak SAY_SUBMERGE_2'),
(-1601021,'Your armor is useless against my locusts!',14060,1,0,0,'anubarak SAY_LOCUST_1'),
(-1601022,'The pestilence upon you!',14067,1,0,0,'anubarak SAY_LOCUST_2'),
(-1601023,'Uunak-hissss tik-k-k-k-k!',14068,1,0,0,'anubarak SAY_LOCUST_3'),
(-1601024,'Ahhh... RAAAAAGH! Never thought... I would be free of him...',14069,1,0,0,'anubarak SAY_DEATH');
