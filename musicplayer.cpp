#include<algorithm>
#include <windows.h>
using std::string;

int freq[] {
	220, 233, 247, 262, 277, 294, 311, 330, 349, 370, 392,
	415, 440, 466, 494, 523, 554, 587, 622, 659, 699, 740,
	784, 831, 880, 932, 988, 1047, 1109, 1175, 1245, 1319,
	1397, 1480, 1568};

int f[1024], d[1024], p;

void Parse(int bpm, string s) {
	int ONENOTE = 1000.0 / ((double)bpm / 60.0);
	s += "$$";
	for (int i = 0; i != s.size(); ++i) {
		if (s[i] == '$') break;
		if (s[i] == ' ') continue;
		int id = 13; int dur = ONENOTE;
		bool fg = false;
		switch (s[i]) {
			case '1': id = 3; break;
			case '2': id = 5; break;
			case '3': id = 7; break;
			case '4': id = 8; break;
			case '5': id = 10; break;			
			case '6': id = 12; break;
			case '7': id = 14; break;
			case '0': fg = true; break;
		}
		id += 12;
		
		int j = i + 1;
		for (; s[j] != ' ' && s[j] != '$'; ++j) {
			if (s[j] == '^') id += 12;
			if (s[j] == '_') id -= 12;
			if (s[j] == 'u') ++id;
			if (s[j] == 'd') --id;
			if (s[j] == '~') dur += ONENOTE;
			if (s[j] == '.') dur += ONENOTE >> 1;
			if (s[j] == '`') dur >>= 1;
		}
		f[++p] = freq[id];
		if (fg) f[p] = 0;
		d[p] = dur;
		i = j - 1;
	}
}

void Play() {
	for (int i = 1; i <= p; ++i) {
//		printf("%d %d\n", f[i], d[i]);
		Beep(f[i], d[i]);
	}
}

const string MUSIC_SCORE = 
//	"1^~.` 2^.` 5~.` 6.` 4.` 2.` 7d~.` 4.` 1^~.` 4.` 3.` 1.` "
//	"1^~.` 2^.` 5~.` 6.` 4.` 2.` 7d~.` 4.` 1^~.` 4^.` 3^. "
//	"1^~.` 2^.` 5~.` 6.` 4.` 2.` 7d~.` 4.` 1^~.` 4.` 3.` 1.` "
//	"1^~.` 2^.` 5~.` 6.` 4.` 2.` 7d~.` 4.` 1^~.` 4^.` 3^. "
	"5 6 1^ 6 "
;

int main() {
	Sleep(200);
	
	Parse(180, MUSIC_SCORE);
	while(1){
		Play();
		Sleep(1000);
	}
	
	return 0;
}
