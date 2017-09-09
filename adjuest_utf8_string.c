U8* adjust_end_of_utf8(U8* source, U8 lenth){
	U8 *p = source, i = 0;
	while(i < lenth){
		if (*p == 0)  return source;
		if (*p >= 0xF0){
			if (i + 4 < lenth){
				p += 4;  i += 4;
				continue;
			}
			else{  *p = 0;  return source;  }
		}
		else if (*p >= 0xE0){
			if (i + 3 < lenth){
				p += 3;  i += 3;
				continue;
			}
			else{  *p = 0;  return source;  }
		}
		else if (*p >= 0xC0){
			if (i + 2 < lenth){
				p += 2;  i += 2;
				continue;
			}
			else{  *p = 0;  return source;  }
		}
		else if (*p < 0x80){
			if (i + 1 < lenth){
				++p;  ++i;
				continue;
			}
			else{  *p = 0;  return source;  }
		}
		else{  *p = 0;  return source;  }
	}
	return source;
}
