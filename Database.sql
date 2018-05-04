CREATE TABLE IF NOT EXISTS Characters(
  Name    VARCHAR(50) NOT NULL PRIMARY KEY,
  Class   INTEGER     NOT NULL
);
|
CREATE TABLE IF NOT EXISTS Instances(
  Name        VARCHAR(50) NOT NULL PRIMARY KEY,
  BossCount   INTEGER     NOT NULL,
  KillCount   INTEGER     DEFAULT 0
);
|
CREATE TABLE IF NOT EXISTS CharacterInstances (
  CharacterName VARCHAR(50) NOT NULL,
  InstanceName  VARCHAR(50) NOT NULL,
  Killed      BOOLEAN DEFAULT FALSE,
  FOREIGN KEY (CharacterName) REFERENCES Characters (Name),
  FOREIGN KEY (InstanceName) REFERENCES Instances (Name),
  CONSTRAINT pkCharInst PRIMARY KEY (CharacterName, InstanceName)
);
|
CREATE TABLE IF NOT EXISTS ResetLog (
  LastReset TEXT  NOT NULL
);
|
CREATE TRIGGER IF NOT EXISTS CreateCharacterInstancesNewInstance AFTER INSERT ON Instances
BEGIN
  INSERT INTO CharacterInstances(CharacterName, InstanceName)
    SELECT C.Name, new.Name FROM Characters C;
END;
|
CREATE TRIGGER IF NOT EXISTS CreateCharacterInstancesNewCharacter AFTER INSERT ON Characters
BEGIN
  INSERT INTO CharacterInstances(CharacterName, InstanceName)
    SELECT new.Name, I.Name FROM Instances I;
END;
