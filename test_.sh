CNT=100
#랜덤 숫자 개수
LIMIT=1100
#평가 점수 기준
INDEX=0
ITER=10
#반복 횟수
NUM_OVER=0
MAX=$LIMIT
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
​
while [ $INDEX -lt $ITER ]
do
echo "$INDEX    :   $NUM `./push_swap $ARG | ./checker_Mac $ARG`"
if [ $NUM -ge $LIMIT ]; then
NUM_OVER=`expr $NUM_OVER + 1`
fi
if [ $NUM -gt $MAX ]; then
MAX=$NUM
fi
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
INDEX=`expr $INDEX + 1`
done
echo "$NUM_OVER overred operations for $ITER times"
if [ $NUM_OVER -gt 0 ]; then
echo "Biggest operation number : $MAX"
echo "fix it!!!!!!!!!!"
fi

#jiychoi님 테스트 쉘 스크립트 