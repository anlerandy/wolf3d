# wolf3d
by alerandy & acourtin

for 42

Compatible MacOSX

# How to run
  - `make && ./wolf3d`
  
# Commands
| Commands | Actions |
|---|---|
| `p` | Pause (ingame) |
| `escape` | Close program |
| `w` `arrow up` | Walk forward |
| `s` `arrow down` | Walk backward |
| `a` `arrow left` | Rotation left |
| `d` `arrow right` | Rotation right |
| `shift` | Run |
| `space` | Fire |
| `r` | Reload |
| `~` | Enable/Unable terminal log (debug) |

# Map editing rules
No empty line should be in between two rules.
  - Height amd Texture should always have the same number of characters and lines.
  - Height : 9 = Wall

List of texture :
  - `B` = brick
  - `M` = Metal
  - `S` = Stone
  - `W` = Wood
  - `R` = the 4 colors (default)
  - `-` = Breakable wall

OBJ line rules :
  - J = PLAYER_START (must be set) ex. : `J|1|1|0` = `PLAYER_START|position x|position y|rotation ˚`
  - T = DAY_TIME ex. `T|1` = `DAY_TIME|NIGHT` or `T|0` = `DAY_TIME|DAY`
If `DAY_TIME` is unset, the game will take the last `DAY_TIME` known (default : `DAY`)

# Standalone make rule
A dmg disk can be generate with the Makefile :
  - `make standalone`

Find City42 dmg file in the wolf3d folder.
