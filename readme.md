# Bowling

## Task

Implement the software for the for the bowling game scoring using rules listed bellow. In addition, it has to support:
1. Multiple players (up to 5)
2. Store results to a file (optional)
3. Replay of the stored game (optional)

## Rules of play

A game of bowling consists of ten frames. In each frame, the bowler will have two chances to knock down as many pins
as possible with his bowling ball. In games with more than one bowler, as is common, every bowler will take his frame 
in a predetermined order before the next frame begins. If a bowler is able to knock down all ten pins with the first
ball, he is awarded a strike. If the bowler is able to knock down all 10 pins with the two balls of a frame, it is
known as a spare. Bonuss points are awarded for both of these, depending on what is scored in the next two balls
(for a strike) or one ball (for a spare). The bowler is alowed to throw two extra balls for achieving a strike in the
tenth frame, or one extra ball for acchieving a spare. This allows for a potential of 12 strikes in a single game, and
a maximum score of 300 points, a perfect game. The player with the most points at the end of ten frames wins.

## Scoring

In general, one point in scored for each pin that is knocked over. So if a player bowls over three pins with the first
shot, then six with the second, the player would receive a total of nine points for that frame. If a player knocks down
nine pins with the first shot, but misses with the second, the player would also score nine. When a player fails to
knock down all ten pins after their second ball it is known as an open frame. 
In the event that all ten pins are knocked over by a player in a single frame, bonuses are awarded.

## Strike

When all ten pins are knocked down with the first ball (called a strike and typically rendered as an "X" on a scoresheet),
a player is awarded ten points, plus a bonus of whatever is scored with the next two balls. In this way, the points
scored for the two balls after the strike are counted twice.
The most points that can be scored in a single frame is 30 points (10 for the orogonal strike, plus strikes in the two
subsequent frames).

## Strike in the final
A player who bowls a strike in the tenth (final) frame is awarder two extra balls so as to allow the awarding of 
bonus points. If both these balls also result in strikes, a total of 30 points (10+10+10) is awarded for the frame.


## Spare

A "spare" is awarded when no pins are left standing after the second ball of a frame; i.e., a player uses both balls
of a frame to clear all ten pins. A player achieving a spare is awarded ten points, plus a bonus of whatever is
scored with the next ball (only the first ball is counted). It is typically randered as a slash on scoresheets in
plase of the second pin count for a frame.

## Spare in the final

A player who bowls a spare in the tenth (final) frame is awarded one extra ball to allow for the bonus points.