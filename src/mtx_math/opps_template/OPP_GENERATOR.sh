
MTX_MATH_DIR="../"
STD_OPPS="add sub mul div pow atan2"

# Absolute path to this script, e.g. /home/user/bin/foo.sh
SCRIPT=$(readlink "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")
INCL_DIR="${SCRIPTPATH}/../../../includes/"
echo $SCRIPTPATH


echo $1
if [[ $1 = "re" ]];
then
	echo "HERE WE GO RESET TIME !!!"
	rm "${INCL_DIR}mtx_arithmetic.h"
	for OPP in $(echo $STD_OPPS | xargs)
	do
		OPPDIR="${MTX_MATH_DIR}${OPP}_opps"
		if test -d "${OPPDIR}"; then
			cd "${OPPDIR}"
			rm mtx*.c
#			mv "__BASE_${OPP}_OPPS.c" '__BASE_ZZZ_OPPS.c'
			cd ../opps_template
		fi
	done
fi

for OPP in $(echo $STD_OPPS | xargs)
do
	echo $OPP
	OPPDIR="${MTX_MATH_DIR}${OPP}_opps"
	echo "$OPPDIR"

#: <<'END'
	if test -d "${OPPDIR}"; then
		echo "directory found"
		if test -f "${OPPDIR}/__BASE_${OPP}_OPPS.c"; then
			echo "ALMOST THERE !"
			cd temp_payload
			SED_TITLE_SCRIPT="s/ZZZ/${OPP}/g"
			SED_SCRIPT="s/zzz/${OPP}/g"
			for f in mtx*.c; do
				FNAME=$(echo $f | sed $SED_TITLE_SCRIPT)
				SED_F_SCRIPT="s/FFF/$(printf "%-30s" $FNAME)/g"
				CP_NAME='../'${OPPDIR}"/${FNAME}"
				echo 'copied file '"${CP_NAME}"
				echo "sed script : ${SED_SCRIPT}"
				sed "${SED_F_SCRIPT}" $f > "${CP_NAME}_temp" # "${CP_NAME}" > $CP_NAME
				sed "${SED_SCRIPT}" "${CP_NAME}_temp" > $CP_NAME
			done
			cd ../
			cd $OPPDIR
			rm *_temp
#			BASE_FILE="__BASE_${OPP}_OPPS.c"
#			SED_F_SCRIPT="s/FFF/$(printf "%-30s" ${BASE_FILE})/g"
#			sed "${SED_F_SCRIPT}" '__BASE_ZZZ_OPPS.c' > 'B_temp'
#			sed "${SED_SCRIPT}" 'B_temp' > "${BASE_FILE}"
			rm B_temp '__BASE_ZZZ_OPPS.c'
			TRGT_H="${INCL_DIR}mtx_arithmetic.h"
			if [ ! -f $TRGT_H ];
			then
				echo "TRGT_H not found !"
				cp "${INCL_DIR}ARITH_TEMPLATE" $TRGT_H # "${INCL_DIR}mtx_arithmetic.h"
			elif [ $(tail -n1 $TRGT_H) = '#endif' ];
			then
				echo "TRGT_H found !"
				sed "$d" $TRGT_H
			fi
			UP_OPP=$(echo $OPP | tr '[:lower:]' '[:upper:]')
			echo "\n//// ${UP_OPP} OPERATIONS" | tee -a "${INCL_DIR}mtx_arithmetic.h"
			echo 't_mtx	*'"mtx_${OPP}"'(t_mtx *a, t_mtx *b, t_mtx *out);' | tee -a "${INCL_DIR}mtx_arithmetic.h"
			grep -h 'void' *.c | grep -v 'static' | while read -r line;
			do
				H_FILE="${INCL_DIR}mtx_arithmetic.h"
				echo "${line};" | tee -a $H_FILE # "${INCL_DIR}mtx_arithmetic.h"
			done
			cd ../opps_template
		else
			echo "ERROR creating ${OPP}. The __BASE_ZZZ_OPPS.c should be in the ZZZ_opps directory in the mtx_math/ directory and \
			and	completed with its fonctions."
		fi
	else
		echo "ERROR"
		exit 1
	fi
done
echo "#endif" | tee -a "${INCL_DIR}mtx_arithmetic.h"
