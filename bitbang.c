// bitbang.c - GPIO BitBang example with lib FTDI (FTDI chip)
// based on https://github.com/legege/libftdi/blob/master/examples/bitbang.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep(3)

#include <ftdi.h>


#define BB_UM232H_VID 0x403
#define BB_UM232H_DID 0x6001

// mimic linux pr_xx macros
#define pr_err(fmt, ...) fprintf(stderr,"ERROR: " fmt, ##__VA_ARGS__)
#define pr_debug(fmt,...) printf("DEBUG: "  fmt, ##__VA_ARGS__)

int main(int argc, char **argv)
{
	struct ftdi_context *ftdi = NULL;
	int f=-1;
	int i=0;
	unsigned char buf[1];
	int ret = EXIT_FAILURE;
	struct ftdi_version_info ftdi_ver =  ftdi_get_library_version();

	pr_debug("FTDI library ver='%s' snapshot='%s'\n",ftdi_ver.version_str,ftdi_ver.snapshot_str);
	ftdi = ftdi_new();
	if (ftdi == NULL){
		pr_err("ftdi_new() returned NULL\n");
		goto exit0;
	}

	f = ftdi_usb_open(ftdi, BB_UM232H_VID,BB_UM232H_DID);
	if (f < 0){
		pr_err("ftdi_usb_open(VID=0x%x,DID=0x%x): %s\n",
				BB_UM232H_VID,BB_UM232H_DID,ftdi_get_error_string(ftdi));
		goto exit1;
	}

	// AD0 OUTPUT (bit=1), all others are Input
	f = ftdi_set_bitmode(ftdi, 0x1, BITMODE_BITBANG);
	if (f < 0){
		pr_err("ftdi_set_bitmode(BITBANG): %s\n",
				ftdi_get_error_string(ftdi));
		goto exit2;
	}

	sleep(3); // ugh see base source

	for(i=0;i<4;i++){
		buf[0] = (unsigned char)(i & 1);
		f = ftdi_write_data(ftdi, buf, 1);
		if (f < 0){
			pr_err("ftdi_write_data(): %s\n",
					ftdi_get_error_string(ftdi));
			goto exit3;
		}
		printf("Setting AD0 LED to %d\n",(int)buf[0]);
		sleep(1);
	}


	ret = EXIT_SUCCESS;
exit3:
	ftdi_disable_bitbang(ftdi);
exit2:
	ftdi_usb_close(ftdi);
exit1:
	ftdi_free(ftdi);ftdi=NULL;
exit0:
	printf("Exiting with ret=%d\n",ret);
	return ret;
}

