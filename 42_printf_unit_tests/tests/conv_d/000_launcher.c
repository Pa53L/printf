#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_d.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_d_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_d_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_d";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
