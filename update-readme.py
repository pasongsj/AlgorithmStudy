import requests

# GitHub API 정보
owner = "pasongsj"  # 자신의 GitHub 사용자 이름으로 변경
repo = "AlgorithmStudy"  # 리포지토리 이름으로 변경

url = f"https://api.github.com/repos/{owner}/{repo}/milestones"

# API 요청
response = requests.get(url)

# 응답 데이터 확인
print("API Response Status Code:", response.status_code)
print("API Response Data:", response.text)  # 응답 내용을 출력하여 확인

# JSON 파싱
try:
    milestones = response.json()
except ValueError:
    print("Invalid JSON response")
    milestones = []

# 예상되는 응답 형식인지 확인
if isinstance(milestones, dict) and 'message' in milestones:
    print(f"Error from API: {milestones['message']}")
    milestones = []  # 오류가 있는 경우 빈 목록으로 설정

# README에 추가할 마일스톤 진행 상황 표 생성
table = "| 주차 | 기간 | 상태 | 완료율 |\n"
table += "|------|------|------|-------|\n"

# 마일스톤 완료율 계산 및 테이블 생성
for milestone in milestones:
    if not isinstance(milestone, dict):
        continue  # 잘못된 형식이면 스킵
    title = milestone['title']  # 제목
    html_url = milestone['html_url']  # 마일스톤의 GitHub 기본 링크
    closed_issues_url = f"{html_url}?state=closed"  # Closed 탭으로의 링크
    title_with_link = f"[{title}]({closed_issues_url})"  # 마일스톤 제목에 링크 추가
    description = milestone.get('description', 'No description')  # 설명
    state = "완료" if milestone['open_issues'] == 0 else "진행 중"  # 상태
    open_issues = milestone['open_issues']
    closed_issues = milestone['closed_issues']
    total_issues = open_issues + closed_issues
    progress = (closed_issues / total_issues) * 100 if total_issues > 0 else 0  # 완료율
    
    # 테이블에 데이터 추가
    table += f"| {title_with_link} | {description} | {state} | {progress:.2f}% |\n"

# 디버깅을 위한 테이블 출력
print("Generated Markdown Table:\n", table)

# 기존 README 내용 읽기
with open("README.md", "r", encoding="utf-8") as file:
    readme_content = file.readlines()

# 새로운 README 내용 작성
new_content = []
in_milestone_section = False
for line in readme_content:
    if line.strip() == "### 주차별 진행률":
        in_milestone_section = True
        new_content.append("### 주차별 진행률\n\n")
        new_content.append(table)  # 표를 추가
    elif in_milestone_section and line.startswith("## "):  # 다음 섹션으로 넘어가면 종료
        in_milestone_section = False
    if not in_milestone_section:
        new_content.append(line)

# 업데이트된 README 내용 확인
print("Updated README Content:\n", ''.join(new_content))

# README 파일 업데이트
with open("README.md", "w", encoding="utf-8") as file:
    file.writelines(new_content)

print("README 파일이 업데이트되었습니다.")
