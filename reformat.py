#!/usr/bin/python 

import sys

class HeadingTracker:
  ROMAN_NUMERALS = ["II","III","IV","V","VI","VII","VIII","IX","X"]
  ROMAN = "ROMAN"
  ALPHA = "ALPHA"
  NUM = "NUM"

  def __init__(self):
    self.romanIndex = 0
    self.upperChar = 'A'
    self.number = 1
    self.lastSeen = "" 

  def nextUpperChar(self):
    c = self.upperChar
    self.upperChar = chr(ord(self.upperChar)+1)
    return str(c)

  def nextRoman(self):
    if self.lastSeen == "":
      return "I"
    if self.romanIndex < len(self.ROMAN_NUMERALS):
      val = self.ROMAN_NUMERALS[self.romanIndex]
      self.romanIndex += 1
      return val 
    return ""
  
  def nextNumber(self):
    num = self.number
    self.number += 1
    return str(num)
  
  def getHeadingType(self,hid):
    if self.lastSeen == "":
      return self.ROMAN
    elif hid in self.ROMAN_NUMERALS:
      return self.ROMAN
    elif hid.isdigit():
      return self.NUM
    else:
      return self.ALPHA
  
  def resetNumber(self):
    self.number = 1

  def resetUpperChar(self):
    self.upperChar = 'A'

  def getNextHeadingId(self,hid):
    lastType = self.getHeadingType(self.lastSeen)
    curType = self.getHeadingType(hid)
    
    if curType == self.ALPHA: 
      if lastType == self.NUM:
        self.resetNumber()
      hid = self.nextUpperChar()
    if curType == self.ROMAN: 
      if lastType == self.ALPHA:
        self.resetUpperChar()
      if lastType == self.NUM:
        self.resetNumber()
        self.resetUpperChar()
      hid = self.nextRoman()
    if curType == self.NUM:
      hid = self.nextNumber()
    self.lastSeen = hid
    return hid

def parseHeadingId(line):
  hd = ""
  for c in line:
    if c == '\t' or c == ' ':
      continue
    elif c != '.':
      hd += c
    else:
      break
  return hd


def reformat():
  fd = open(sys.argv[1],"r")
  lines = fd.readlines()
  fd  = open(sys.argv[1],"w")
  tracker = HeadingTracker()
  for l in lines:
    if l.strip() == "":
      fd.write(l)
    else:
      hid = parseHeadingId(l)
      fd.write(l.replace(hid,tracker.getNextHeadingId(hid)))

# Main #
if len(sys.argv) < 2:
  print("./reformat [textfile]")
  exit()
reformat()
