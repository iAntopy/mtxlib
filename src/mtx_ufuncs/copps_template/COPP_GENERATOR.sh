
MTX_CUMUL_DIR="../"
STD_COPPS="sum prod min max mean hypot"

# Absolute path to this script, e.g. /home/user/bin/foo.sh
SCRIPT=$(readlink "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")
INCL_DIR="${SCRIPTPATH}/../../../includes/"
echo $SCRIPTPATH


echo $1
if test $1 = 're';
then
	echo "HERE WE GO RESET TIME !!!"
	rm "${INCL_DIR}mtx_cumul_ufuncs.h"
	for OPP in $(echo $STD_COPPS | xargs)
	do
		OPPDIR="${MTX_CUMUL_DIR}${OPP}_copps"
		if test -d "${OPPDIR}"; then
			cd "${OPPDIR}"
			rm mtx*.c
#			mv "__BASE_${OPP}i_COPPS.c" '__BASE_zzzi_COPPS.c'
#			mv "__BASE_${OPP}f_COPPS.c" '__BASE_zzzf_COPPS.c'
			cd ../copps_template
		fi
	done
fi

for OPP in $(echo $STD_COPPS | xargs)
do
	echo $OPP
	OPPDIR="${MTX_CUMUL_DIR}${OPP}_copps"
	echo "$OPPDIR"

#: <<'END'
#	if [ $(ls -l | grep '__BASE_zzz' | wc -l) = 2 ]
	if test -d "${OPPDIR}"; then
		echo "directory found"
		ls -l $OPPDIR
#		echo "nb files starting with ${OPP} base file __BASE_${OPP} : $(ls -l $OPPDIR | grep __BASE_$OPP | grep '\.c' | wc -l)"
		if [ $(ls -l $OPPDIR | grep __BASE_$OPP | grep '\.c' | wc -l) = 2 ]; then
#		if [-f "${OPPDIR}/__BASE_zzzi_COPPS.c" && -f "${OPPDIR}/__BASE_zzzf_COPPS.c"]; then
			echo "ALMOST THERE !"
			cd temp_payload
			SED_SCRIPT="s/zzz/${OPP}/g"
			for f in mtx*.c; do
				FNAME=$(echo $f | sed $SED_SCRIPT)
				SED_F_SCRIPT="s/fff/$(printf "%-30s" $FNAME)/g"
				CP_NAME='../'${OPPDIR}"/${FNAME}"
				echo 'copied file '"${CP_NAME}"
				echo "sed script : ${SED_SCRIPT}"
				sed "${SED_F_SCRIPT}" $f > "${CP_NAME}_temp" # "${CP_NAME}" > $CP_NAME
				sed "${SED_SCRIPT}" "${CP_NAME}_temp" > $CP_NAME
#				sed "${SED_F_SCRIPT}; ${SED_SCRIPT}" > $CP_NAME
			done
			cd ../
			cd $OPPDIR
			rm *_temp
#			BASE_FILE_I="__BASE_${OPP}i_COPPS.c"
#			BASE_FILE_F="__BASE_${OPP}f_COPPS.c"
#			SED_F_SCRIPT="s/fff/$(printf "%-30s" ${BASE_FILE_I})/g"
#			sed "${SED_F_SCRIPT}" '__BASE_zzzi_COPPS.c' > 'B_temp'
#			sed "${SED_SCRIPT}" 'B_temp' > "${BASE_FILE_I}"
#			SED_F_SCRIPT="s/fff/$(printf "%-30s" ${BASE_FILE_F})/g"
#			sed "${SED_F_SCRIPT}" '__BASE_zzzf_COPPS.c' > 'B_temp'
#			sed "${SED_SCRIPT}" 'B_temp' > "${BASE_FILE_F}"
			rm B_temp '__BASE_zzzi_COPPS.c' '__BASE_zzzf_COPPS.c'
			TRGT_H="${INCL_DIR}mtx_cumul_ufuncs.h"
			if [ ! -f $TRGT_H ];
			then
				echo "TRGT_H not found !"
				cp "${INCL_DIR}CUMUL_TEMPLATE" $TRGT_H # "${INCL_DIR}mtx_cumul_ufuncs.h"
			fi
			UP_OPP=$(echo $OPP | tr '[:lower:]' '[:upper:]')
			echo "\n//// ${UP_OPP} OPERATIONS" | tee -a "${INCL_DIR}mtx_cumul_ufuncs.h"
			echo 't_mtx	*'"mtx_${OPP}"'(t_mtx *mtx, int axis, t_mtx *out);' | tee -a "${INCL_DIR}mtx_cumul_ufuncs.h"
			grep -h 'void' *.c | grep -v 'static' | while read -r line;
			do
				echo "${line};" | tee -a $TRGT_H # "${INCL_DIR}mtx_cumul_ufuncs.h"
			done
			cd ../copps_template
		else
			echo "ERROR creating ${OPP}. The __BASE_zzzi_COPPS.c and __BASE_zzzf_COPPS.c files should be in the zzz_copps directory in the mtx_ufuncs/ directory and \
			and	completed with its functions."
		fi
	else
		echo "ERROR"
		exit 1
	fi
done
echo "#endif" | tee -a "${INCL_DIR}mtx_cumul_ufuncs.h"
