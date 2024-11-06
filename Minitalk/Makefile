CC = cc
CFLAGS = -Wall -Wextra -Werror
TEST_CFLAGS = -g
CLIB_DIR = libft
CLIB = ft

NAME_CLIENT = client
NAME_SERVER = server
SRCS_CLIENT = main_client.c utils_client.c
SRCS_SERVER = main_server.c utils_server.c
HEAD_CLIENT = client.h
HEAD_SERVER = server.h
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

NAMES = $(NAME_CLIENT) $(NAME_SERVER)

# 17 char
MESSAGE = "42Prague is best!"
# 100 char
MESSAGE1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas rhoncus pharetra orci dapibus nam."
# 256 char
MESSAGE3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent tempor lacinia nisl, non aliquam ex vulputate non. Cras ut porttitor nulla, ac placerat felis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis porttitor."
# 998 char
MESSAGE4 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum."
# UNICODE
MESSAGE5 = "⡨ⲷ⋼⸦▻ⳁ⇶∳Ⳕ₈⠸Ⓝ∽┗⩓Ⓢ⥺⓫ⷤ⚡‼⯏⽶⚀⫽⦐②≏⥠⨝ⳅⴻⅦ"
# 10016 char
MESSAGE6 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse non lobortis tellus. Cras fermentum mattis velit, aliquet rutrum lacus interdum sit amet. Donec vitae lacinia dui, facilisis tempor massa. Aenean pharetra hendrerit neque, a eleifend mauris ultricies sit amet. Duis at massa consequat, dictum ipsum eget, venenatis nunc. Ut a mi et felis gravida commodo. Etiam mollis consequat lacus, vel semper nunc sollicitudin a. Pellentesque sit amet ligula quis nibh consectetur feugiat non in quam. Sed sollicitudin, nisi eget volutpat viverra, libero nibh lacinia dolor, at rutrum diam ipsum sed dui. Vivamus sodales sem nec diam mattis venenatis. Morbi bibendum odio dolor, et cursus est efficitur in. Vivamus placerat sed odio ac vehicula. Proin quis leo risus. Phasellus feugiat semper lectus sit amet consectetur. Nam ultricies dui dolor, et dapibus elit aliquet vel. Nulla non interdum quam. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris vel ultrices mauris, sit amet eleifend eros. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Sed fringilla leo augue. Curabitur porta lorem arcu, ut lobortis est tristique id. Mauris aliquam ante et lacinia dictum. Nullam ornare odio ac erat pellentesque tristique. Sed a tristique mi. Mauris venenatis auctor lorem, quis convallis metus facilisis in. Cras maximus erat eget rhoncus dignissim. Aenean ligula dui, viverra vitae felis at, elementum varius dolor. Ut tincidunt ipsum arcu. Aliquam cursus odio diam, in pharetra metus elementum eu. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur nulla nulla, malesuada at gravida eu, efficitur non odio. Donec a diam sed erat lacinia tempor. Cras gravida laoreet ex. Pellentesque pharetra, purus eu pharetra egestas, tortor lorem porttitor ligula, at posuere justo magna id orci. Duis tincidunt vehicula urna eu auctor. Ut vitae ultrices tortor. Pellentesque libero ipsum, porta a commodo sed, efficitur a massa. Aliquam sapien sem, vehicula eu velit eget, volutpat hendrerit purus. Cras at malesuada purus. Pellentesque lacinia eros bibendum felis suscipit, ut viverra mi auctor. Aenean nibh diam, consequat in vulputate eget, egestas id libero. Aliquam rhoncus ante nec eros porta, quis vehicula erat lobortis. Pellentesque commodo gravida orci sed faucibus. Donec in nunc lacus. Donec rutrum mauris eget mauris pellentesque placerat. Vestibulum eleifend quam felis, non sollicitudin est tempus sit amet. Phasellus vestibulum dolor placerat varius maximus. Suspendisse rutrum velit lacus, in blandit nisi lobortis sit amet. Etiam vel ex suscipit turpis elementum posuere a et massa. Duis pulvinar, justo ut dignissim luctus, urna quam feugiat mauris, ac elementum est lectus bibendum orci. Donec ac felis ut lectus fermentum cursus nec in nisl. Ut aliquam velit vel ligula imperdiet, non vestibulum dui aliquam. Etiam eleifend purus quis sodales luctus. Sed placerat ornare molestie. Integer augue tortor, ultricies vel ornare ut, iaculis vitae tortor. Integer id nisl non nibh rutrum consectetur eu eu ipsum. Ut pulvinar, augue non tristique suscipit, massa libero cursus eros, eu luctus odio turpis convallis nisi. Etiam vel quam rhoncus ex euismod euismod at nec metus. Nam auctor odio eu turpis interdum aliquam. Duis quis sem sit amet felis molestie fermentum. Praesent mauris metus, hendrerit non semper ut, porta ac lectus. Aenean eu nisi magna. Nunc malesuada purus sit amet nisl vestibulum, id eleifend metus egestas. Ut vehicula volutpat vestibulum. Proin consequat velit id ultricies rutrum. Sed fermentum mi et nisi faucibus rutrum. Praesent molestie velit est, sed gravida mauris finibus venenatis. Vestibulum ac placerat nibh. Quisque a viverra enim. Integer imperdiet sagittis accumsan. Integer feugiat lectus id ante finibus, nec sagittis dui malesuada. Cras pulvinar erat lectus, in maximus dui dignissim at. Curabitur aliquet metus dui, eget facilisis lacus laoreet eu. Vivamus volutpat nulla et turpis tempus, vitae aliquam leo fringilla. Vivamus interdum velit ante, et luctus orci aliquet a. Donec euismod, quam ut lobortis hendrerit, nibh augue suscipit ipsum, ac aliquam lectus dui id lacus. Phasellus hendrerit felis sed consequat ornare. Donec nec odio id sapien auctor vehicula nec viverra erat. Etiam non luctus lorem, at laoreet felis. Aliquam sagittis sit amet dui et elementum. Sed feugiat lectus vel velit hendrerit pharetra. Curabitur lorem augue, ultricies et laoreet sit amet, imperdiet in nisl. Quisque est sapien, tempus eget consequat quis, malesuada quis orci. Morbi aliquam laoreet nulla sit amet ullamcorper. Fusce facilisis, risus vitae bibendum viverra, enim lacus egestas nibh, id rhoncus ante sem a metus. Cras in tincidunt lorem. Quisque egestas interdum viverra. Aenean at ultricies libero. Praesent rutrum, lacus ac laoreet porta, elit metus consectetur erat, eu sodales quam nibh nec quam. Etiam at velit odio. Morbi quis nibh lacus. Aliquam erat volutpat. Nunc ornare massa turpis, et maximus sem vulputate a. Integer a euismod nibh. Aenean sed metus at sapien aliquam dapibus sit amet eu diam. Etiam leo mauris, molestie sit amet sodales quis, maximus nec justo. Donec vel libero tortor. Nulla facilisi. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Vivamus tincidunt eros non eros rutrum faucibus. Vivamus nisl ipsum, facilisis vitae ipsum eget, rhoncus viverra orci. Suspendisse laoreet est vitae posuere ultricies. Integer venenatis accumsan libero, et aliquet neque pharetra eget. Vestibulum lobortis cursus risus ut venenatis. Fusce augue mauris, iaculis non dolor scelerisque, lacinia maximus magna. Etiam ut elit at nisi eleifend malesuada. Nunc viverra efficitur faucibus. Sed nibh orci, tincidunt vel nunc ullamcorper, imperdiet molestie augue. Suspendisse ut nisi nunc. Nullam vitae mi non nisi ultricies sollicitudin id non eros. Nullam lacinia laoreet mattis. Curabitur vel urna ullamcorper odio lobortis posuere eget ut felis. Phasellus interdum nisl risus, ut vulputate justo tincidunt eget. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam erat volutpat. Vestibulum tellus lectus, pretium et metus eu, congue dictum tortor. Fusce aliquam iaculis mattis. Proin in augue at ante faucibus facilisis. Proin posuere libero turpis, ac finibus elit bibendum at. Quisque sollicitudin ex tellus, a volutpat urna faucibus sed. Sed in lacinia magna. Duis mollis, metus et vestibulum fermentum, purus leo pretium odio, nec varius turpis velit id tellus. Proin maximus pellentesque tortor, sed tempor purus ullamcorper quis. Vestibulum vel orci at turpis euismod pellentesque ut vel quam. Nulla dapibus massa at est euismod pulvinar. Vestibulum venenatis, risus semper feugiat gravida, ligula felis cursus lacus, sit amet sodales erat orci sed justo. Ut imperdiet neque vel odio iaculis varius a non mi. Aliquam maximus vitae metus ut porta. Sed eu molestie quam. In faucibus interdum turpis, at vehicula nibh feugiat tempor. Praesent lobortis rutrum ipsum, quis lobortis risus accumsan mattis. Curabitur bibendum blandit turpis. Nam volutpat, risus et convallis dapibus, nibh ligula egestas risus, aliquet vulputate risus nisi quis velit. Vestibulum laoreet diam risus, egestas hendrerit nulla ullamcorper eget. Ut imperdiet mi dolor. Morbi maximus ultricies diam quis commodo. Suspendisse potenti. Vestibulum tincidunt ligula quis convallis posuere. Donec vestibulum ex vel ultricies accumsan. Duis ultricies placerat libero ut aliquet. Sed sit amet lectus ut orci elementum molestie. Duis eu dui et erat ornare mollis. Duis sit amet elit facilisis, viverra massa et, interdum tortor. Maecenas sodales fringilla volutpat. Etiam efficitur sapien dui, at eleifend ipsum sollicitudin vitae. Ut sit amet ipsum urna. Nullam elementum iaculis dolor, nec bibendum quam elementum et. Fusce augue leo, pharetra id ullamcorper eu, elementum in sem. Mauris ac enim in eros interdum commodo quis sit amet urna. Duis arcu velit, ultricies in tempus non, hendrerit mattis velit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Nunc vestibulum commodo metus, quis viverra justo mollis in. Pellentesque efficitur ante risus, ac laoreet arcu dictum non. Donec vitae tristique nibh. Maecenas feugiat pretium vulputate. Vivamus quam massa, vestibulum ac nibh facilisis, gravida finibus libero. Vestibulum consequat rutrum condimentum. Sed convallis elit sit amet nibh tincidunt, at venenatis tortor laoreet. Sed ac pretium nisl. Nulla velit purus, ornare nec maximus feugiat, luctus at risus. Sed vestibulum tortor urna, at varius urna euismod ac. Aliquam erat volutpat. Morbi et facilisis risus, vel euismod magna. Vestibulum sed condimentum lacus. Vestibulum ipsum nulla, aliquet et scelerisque sed, faucibus at enim. Sed efficitur ligula sit amet nisi dapibus gravida. Pellentesque sapien quam, consequat non sem nec, blandit eleifend purus. Vestibulum consectetur leo eros, vel tincidunt velit ullamcorper maximus. Donec elementum eros vitae ante accumsan, euismod vulputate ipsum molestie. Cras posuere nibh eu magna laoreet pharetra. Donec vestibulum, ex eu congue commodo, velit elit elementum nisi, id semper metus eros a massa. Nam suscipit orci urna, posuere consequat metus semper accumsan. Pellentesque dictum, lacus vel ultricies convallis, dui enim porttitor leo, a sagittis augue nisi ut ex. Mauris lobortis placerat quam quis pharetra. In hac habitasse platea dictumst. Suspendisse vulputate efficitur nisl. Mauris vel sapien urna. Phasellus nisl risus, sodales quis commodo accumsan, dictum placerat orci. Aliquam congue arcu sed quam congue suscipit. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed mollis, tortor vel ultrices cursus, metus leo sagittis arcu, at malesuada tortor lectus nec magna. Suspendisse non tincidunt mi. Phasellus aliquam aliquet ultrices. Proin in est vitae nisl sagittis venenatis vel non felis. In sit amet augue ac nibh sodales tincidunt."

.PHONY: all clean fclean re run_client run_server norm memleak_client memleak_server

all: $(NAMES)

$(NAME_CLIENT): $(OBJS_CLIENT) $(HEAD_CLIENT)
	make -C $(CLIB_DIR)
	$(CC) $(TEST_CFLAGS) -o $@ $(OBJS_CLIENT) -L$(CLIB_DIR) -l$(CLIB)

$(NAME_SERVER): $(OBJS_SERVER) $(HEAD_SERVER)
	make -C $(CLIB_DIR)
	$(CC) $(TEST_CFLAGS) -o $@ $(OBJS_SERVER) -L$(CLIB_DIR) -l$(CLIB)

clean:
	find . -name '*.o' -type f -delete
	find . -name '*.a' -type f -delete

fclean: clean
	rm -f $(NAMES)

re: fclean all

run_client: $(NAME_CLIENT)
	# -./$< $(PID) $(MESSAGE)
	# -./$< $(PID) $(MESSAGE1)
	# -./$< $(PID) $(MESSAGE2)
	# -./$< $(PID) $(MESSAGE3)
	# -./$< $(PID) $(MESSAGE4)
	# -./$< $(PID) $(MESSAGE5)
	# -./$< $(PID) $(MESSAGE6)

run_server: $(NAME_SERVER)
	-./$<

norm:
	norminette

memleak_client: $(NAME_CLIENT)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$< $(PID) $(MESSAGE)

memleak_server: $(NAME_SERVER)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$<
