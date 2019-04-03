from subprocess import check_output

def run(str):
	return check_output(str.split())

result = dict()
problem_names = run("ls ./problems").split()
print(problem_names)

for team_data_folder_name in run("ls ./codes").split():
	print(team_data_folder_name)
	team_txt = run("cat ./codes/%s/Team.txt" % team_data_folder_name)
	# team_txt = team_txt.split("\n")[ : -2].join("\n")
	print(team_txt)
	result[team_txt] = []
	for problem_code in run("ls ./codes/%s" % team_data_folder_name).split():
		if problem_code != "Team.txt":
			run("g++ ./codes/%s/%s" % (team_data_folder_name, problem_code))
			print("Compiled")
	break