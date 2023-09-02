#include <stdio.h>
#include <string.h>

#define VER "1.0"
// 0x930 * 4 = 0x24C0 = start of sector 4
// 0x24C0 + 0x18 = 0x24D8 = start of sector 4 user data after sync header (0x18)
// 0x91E = 0x24D to 0x2DEF = sector 4 user data + EEC + EDC (0x800 + 0x114 + 0x04)
// 0x930 * 15 = 0x89D0 = start of sector 15
// 0x89D0 + 0x18 = 0x89E8 = start of sector 15 user data after sync header (0x18)
// 0x930 * 12 =  0x776 = 0x6E40 + 0x118 = 0x776C
// NOTE: EDC moved to sector 15 is invalid as it is from sector 4 using sector 4 sync data. We need to run EDCRE (without -z arg) after this program to fix sector 15 only
unsigned char sector_moved[0x918];
FILE * data_track;
FILE * license_out;

int main (int argc, const char * argv[]) 
{
    printf("Move Sector (MovSec) For TOCPerfect Patcher\nv%s By Alex Free (C)2023 (3-BSD)\n\n", VER);

   if(argc == 3)
    {
        if((strcmp("-r", argv[1])) == 0) 
		{
        	if((data_track = fopen(argv[2], "rb")) == NULL)
        	{
				printf("Error: can not open %s\n", argv[1]);
				return(1);
			}

        	if((license_out = fopen("license_sector.dat", "wb+")) == NULL)
        	{
				fclose(data_track);
				printf("Error: can not create license_sector.dat\n");
				return(1);
			}

			fseek(data_track, 0x24D8, SEEK_SET);
			printf("Reading sector 4 User Data/EEC/EDC\n");
		
			for(int i=0; i < 0x918; i++)
				fread(&sector_moved[i], 1, 1, data_track);

			fseek(license_out, 0, SEEK_SET);
			printf("Writing sector 4 User Data/EEC/EDC to license_sector.dat\n");
		
			for(int i=0; i < 0x918; i++)
				fwrite(&sector_moved[i], 1, 1, license_out);

			fclose(data_track);
			fclose(license_out);
		} else if((strcmp("-w", argv[1])) == 0) {
        	if((data_track = fopen(argv[2], "rb+")) == NULL)
        	{
				printf("Error: can not open %s\n", argv[1]);
				return(1);
			}

        	if((license_out = fopen("license_sector.dat", "rb")) == NULL)
        	{
				fclose(data_track);
				printf("Error: can not open an existing license_sector.dat\n");
				return(1);
			}

			fseek(license_out, 0, SEEK_SET);
			printf("Reading sector 4 User Data/EEC/EDC from license_sector.dat\n");
		
			for(int i=0; i < 0x918; i++)
				fread(&sector_moved[i], 1, 1, license_out);

			printf("Deleting license_sector.dat\n");
			remove("license_sector.dat");

			printf("Writing sector 4 User Data/EEC/EDC to Sector 15\n");
			fseek(data_track, 0x89E8, SEEK_SET);
		
			for(int i=0; i < 0x918; i++)
				fwrite(&sector_moved[i], 1, 1, data_track);

			printf("Writing sector 12 EDC for EDC protected games\n");
			fseek(data_track, 0x776C, SEEK_SET);
			for(int i = 0; i < 4; i++)
				fwrite("\0", 1, 1, data_track);

			fclose(data_track);
			fclose(license_out);
		} else {
			printf("Error: incorrect first argument, it must be -r or -w\n");
			return(1);
		}
	} else {
		printf("Error: incorrect number of arguments\nUsage:\nmovsec <track 01.bin>\n");
		return(1);
	}
}
