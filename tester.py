from subprocess import check_output as chkout, CalledProcessError

def run(cmd, timeout = 1):
	print("Runnning cmd:", cmd)
	return chkout(["bash", "-c", cmd], timeout = timeout).decode()

result = dict()

run("rm results.csv")
result_file = open("results.txt", "w")

for team_data_folder_name in run("ls ./codes").split():
	print(team_data_folder_name)
	team_txt = run("cat ./codes/%s/Team.txt" % team_data_folder_name)
	print(team_txt)
	curr_user_score = dict()
	for problem_code in run("ls ./codes/%s" % team_data_folder_name).split():
		if problem_code != "Team.txt":
			try:
				run("g++ ./codes/%s/%s" % (team_data_folder_name, problem_code), timeout = 30)
			except CalledProcessError:
				print("Compilation failed")
				continue
			print("Compiled %s" % problem_code)
			problem_name = problem_code[ : -4]
			# print(problem_name)
			accepted = True
			for test_input in run("ls ./tests/%s/inputs" % (problem_name, )).split():
				print(test_input)
				try:
					print("runnning")
					run("./a.out < ./tests/%s/inputs/%s > ./out_temp.txt" % (problem_name, test_input), timeout = 3)
				except:
					print("failed")
					accepted = False
					run("echo '' > out_temp.txt")
				print("Executed on test case")
				test_output = "output" + test_input[5 : ]
				check_output = run("wdiff -s out_temp.txt ./tests/%s/outputs/%s | tail -n 1" % (problem_name, test_output), timeout = 1000)
				common_percent = int(check_output.split()[4][ : -1])
				print("percent common:", common_percent)
				if common_percent != 100:
					print("wrong answer")
					accepted = False
			if accepted:
				print("ACCEPTED")
				check_output = run("wdiff -s ./codes/%s/%s ./samples/%s | tail -n 1" % (team_data_folder_name, problem_code, str(problem_name) + ".cpp"), timeout = 1000)
				print("ck: ", check_output)
				common_percent = int(check_output.split()[4][ : -1])
				curr_user_score[problem_name] = common_percent
	result[team_txt] = curr_user_score
	result_file.write(team_txt);
	result_file.write("\n" + "-" * 80 + "\n")
	result_file.write(str(curr_user_score) + "\n")
	result_file.write("=" * 80 + "\n")
	result_file.flush()
run("rm a.out out_temp.txt")
print(result)